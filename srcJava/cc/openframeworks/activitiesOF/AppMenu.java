package cc.openframeworks.activitiesOF;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
 
public class AppMenu extends Activity {
    // Initializing variables
    EditText inputName;
    EditText inputEmail;
    
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.app_menu);
 
    }
    
    public void nativeActivity(View view){
    	
        launchNativeContext();

    }
    public void kuboActivity(View view){
    	
        launchOFContext();

    }
    
    public void launchNativeContext(){

    	
        Intent i = new Intent(getBaseContext(), FirstScreenActivity.class);
		startActivityForResult(i, 1);  
    	
    }
    
    public void launchOFContext(){
    	
        
        Intent i = new Intent(getBaseContext(), OFActivity.class);
		startActivityForResult(i, 1);
        
    	
    }
    
    
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {

		if (requestCode == 1) {

			if (resultCode == RESULT_OK) {
				String result = data.getStringExtra("result");
			}
			if (resultCode == RESULT_CANCELED) {
				Log.v("AppMenu", "Last activity closed with error");
			}
		}
	}// onActivityResult
    
    
}
