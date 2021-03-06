package com.reviso.marcello_ocrlab.ocrlab;

import android.app.Activity;
import android.content.ContentResolver;
import android.content.Context;
import android.content.Intent;
import android.content.res.AssetFileDescriptor;
import android.content.res.AssetManager;
import android.content.res.Resources;
import android.database.Cursor;
import android.graphics.Bitmap;
import android.net.Uri;
import android.os.ParcelFileDescriptor;
import android.provider.MediaStore;
import android.provider.Settings;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.webkit.MimeTypeMap;
import android.widget.ImageView;

import java.io.File;
import java.io.FileDescriptor;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

public class MainActivity extends AppCompatActivity {

    private static final int READ_REQUEST_CODE = 1337;
    private static final int ROTATE_REQUEST_CODE = 1338;
    private static final int RECOGNIZE_REQUEST_CODE = 1339;

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

        ImageView imageView = (ImageView) findViewById(R.id.imageView);
        imageView.setImageResource(R.mipmap.ic_launcher);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        if (item.getItemId() == R.id.menu_item_open_file) {
            performFileSearch(READ_REQUEST_CODE);
        }
        else if (item.getItemId() == R.id.menu_item_rotate_file) {
            performFileSearch(ROTATE_REQUEST_CODE);
        }
        else if (item.getItemId() == R.id.menu_item_recognize_file) {
            performFileSearch(RECOGNIZE_REQUEST_CODE);
        }
        return true;
    }

    public void performFileSearch(int requestCode) {

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
        intent.setType("image/*");

        startActivityForResult(intent, requestCode);
        // END_INCLUDE (use_open_document_intent)
    }

    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent resultData) {
        // BEGIN_INCLUDE (parse_open_document_response)
        // The ACTION_OPEN_DOCUMENT intent was sent with the request code READ_REQUEST_CODE.
        // If the request code seen here doesn't match, it's the response to some other intent,
        // and the below code shouldn't run at all.

        if ((requestCode == READ_REQUEST_CODE ||
                requestCode == ROTATE_REQUEST_CODE ||
                requestCode == RECOGNIZE_REQUEST_CODE) && resultCode == Activity.RESULT_OK) {
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

                Bitmap image;
                if (requestCode == RECOGNIZE_REQUEST_CODE) {
                    AssetManager am = getAssets();
                    try {
                        String[] tessdata = am.list("tessdata");
                        File cacheDir = getCacheDir();
                        File tessData = new File(cacheDir, "tessdata");
                        if (!tessData.exists()){
                            tessData.mkdir();
                        }
                        for (String item:tessdata) {
                            InputStream istream = am.open(String.format("tessdata/%s", item));
                            File ofile = new File(tessData, item);
                            FileOutputStream ostream = new FileOutputStream(ofile);
                            CopyStream(istream, ostream);
                            Log.d("OCRLAB", "onActivityResult: copied " + ofile.getAbsolutePath());
                        }
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                    recognize(getCacheDir().getAbsolutePath(), stream);
                    return;
                }
                else if (requestCode == ROTATE_REQUEST_CODE) {
                    image = Rotate(stream);
                } else {
                    MimeTypeMap mime = MimeTypeMap.getSingleton();
                    String type = mime.getExtensionFromMimeType(cR.getType(uri));
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
                }
                try {
                    stream.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }

                ImageView imageView = (ImageView) findViewById(R.id.imageView);
                if (image != null) {
                    assert imageView != null;
                    imageView.setImageBitmap(image);
                    //imageView.setImageBitmap(scaleDown(image, 1080, false));
                } else {
                    imageView.setImageResource(R.mipmap.ic_launcher);
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

    public void CopyStream(InputStream is, OutputStream os) {
        final int buffer_size = 4096;
        try {
            byte[] bytes = new byte[buffer_size];
            for (int count=0;count!=-1;) {
                count = is.read(bytes);
                if(count != -1) {
                    os.write(bytes, 0, count);
                }
            }
            os.flush();
            is.close();
            os.close();
        } catch (Exception ex) {
            Log.e("OCRLAB",ex.getMessage());
        }
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String pngLibVersion();
    public native Bitmap loadTiff(FileInputStream stream);
    public native Bitmap loadPng(FileInputStream stream);
    public native Bitmap loadJpeg(FileInputStream stream);
    public native Bitmap Rotate(FileInputStream stream);
    public native Object recognize(String tessData, FileInputStream stream);
}
