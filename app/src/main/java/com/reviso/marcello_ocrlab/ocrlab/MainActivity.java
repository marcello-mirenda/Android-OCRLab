package com.reviso.marcello_ocrlab.ocrlab;

import android.app.Activity;
import android.content.ContentResolver;
import android.content.Intent;
import android.graphics.Bitmap;
import android.net.Uri;
import android.os.ParcelFileDescriptor;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.webkit.MimeTypeMap;
import android.widget.ImageView;
import java.io.FileDescriptor;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

public class MainActivity extends AppCompatActivity {

    private static final int READ_REQUEST_CODE = 1337;

    // Used to load the 'native-lib' library on application startup.
    static {
        try {
            System.loadLibrary("com-reviso-marcello-ocrlab-native-lib");
        }
        catch (Exception ex)
        {
            Log.e("OCRLab", "static initializer: ", ex);
        }
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        if (item.getItemId() == R.id.menu_item_open_file) {
            performFileSearch();
        }
        return true;
    }

    public void performFileSearch() {

        // BEGIN_INCLUDE (use_open_document_intent)
        // ACTION_OPEN_DOCUMENT is the intent to choose a file via the system's file browser.
        Intent intent = new Intent(Intent.ACTION_OPEN_DOCUMENT);

        // Filter to only show results that can be "opened", such as a file (as opposed to a list
        // of contacts or timezones)
        intent.addCategory(Intent.CATEGORY_OPENABLE);

        // Filter to show only images, using the image MIME data type.
        // If one wanted to search for ogg vorbis files, the type would be "audio/ogg".
        // To search for all documents available via installed storage providers, it would be
        // "*/*".
        intent.setType("*/*");

        startActivityForResult(intent, READ_REQUEST_CODE);
        // END_INCLUDE (use_open_document_intent)
    }

    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent resultData) {
        // BEGIN_INCLUDE (parse_open_document_response)
        // The ACTION_OPEN_DOCUMENT intent was sent with the request code READ_REQUEST_CODE.
        // If the request code seen here doesn't match, it's the response to some other intent,
        // and the below code shouldn't run at all.

        if (requestCode == READ_REQUEST_CODE && resultCode == Activity.RESULT_OK) {
            // The document selected by the user won't be returned in the intent.
            // Instead, a URI to that document will be contained in the return intent
            // provided to this method as a parameter.  Pull that uri using "resultData.getData()"
            if (resultData != null) {
                Uri uri = resultData.getData();

                ContentResolver cR = getContentResolver();

                ParcelFileDescriptor parcelFileDescriptor = null;
                try {
                    parcelFileDescriptor = cR.openFileDescriptor(uri, "r");
                } catch (FileNotFoundException e) {
                    e.printStackTrace();
                }
                assert parcelFileDescriptor != null;
                FileDescriptor fileDescriptor = parcelFileDescriptor.getFileDescriptor();

                FileInputStream stream = new FileInputStream(fileDescriptor);

                MimeTypeMap mime = MimeTypeMap.getSingleton();
                String type = mime.getExtensionFromMimeType(cR.getType(uri));
                Bitmap image;
                switch (type)
                {
                    case "jpg":
                        image = loadJpeg(stream);
                        break;
                    case "png":
                        image = loadPng(stream);
                        break;
                    case "tiff":
                        image = loadTiff(stream);
                        break;
                    default:
                        image = null;
                        break;
                }

                try {
                    stream.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }

                if (image != null) {
                    ImageView imageView = (ImageView) findViewById(R.id.imageView);
                    assert imageView != null;
                    imageView.setImageBitmap(image);
                    //imageView.setImageBitmap(scaleDown(image, 1080, false));
                }
            }
            // END_INCLUDE (parse_open_document_response)
        }
    }

    public static Bitmap scaleDown(Bitmap realImage, float maxImageSize,
                                   boolean filter) {
        float ratio = Math.min(
                (float) maxImageSize / realImage.getWidth(),
                (float) maxImageSize / realImage.getHeight());
        int width = Math.round((float) ratio * realImage.getWidth());
        int height = Math.round((float) ratio * realImage.getHeight());

        Bitmap newBitmap = Bitmap.createScaledBitmap(realImage, width,
                height, filter);
        return newBitmap;
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String pngLibVersion();
    public native Bitmap loadTiff(FileInputStream stream);
    public native Bitmap loadPng(FileInputStream stream);
    public native Bitmap loadJpeg(FileInputStream stream);
}
