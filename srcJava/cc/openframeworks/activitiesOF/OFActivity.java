package cc.openframeworks.activitiesOF;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.KeyEvent;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import cc.openframeworks.OFAndroid;


public class OFActivity extends cc.openframeworks.OFActivity{
	
	/**
	 * When call this method, it runs the C++ code in ofApp.cpp
	 */
	public native void callCmethod();
		
	@Override
    public void onCreate(Bundle savedInstanceState)
    { 
        super.onCreate(savedInstanceState);
        String packageName = getPackageName();

        ofApp = new OFAndroid(packageName,this);
        
    } 
	
	public void showOFlogMessage(View view){	
		/**
		 * Call native method (code in C++, stored at ofApp.cpp)
		 */
		callCmethod();
		
	    Log.v("OFActiviy", "openActivity method in java native class access via Android Native UI");
				
	}
	public void openActivity(){
		
		 Log.v("OFActiviy", "openActivity method in java native class access via OF");
		 
		 
		Intent i = new Intent(getBaseContext(), FirstScreenActivity.class);
		startActivityForResult(i, 1);  
		 
		 
		
//		Intent nextScreen = new Intent(getApplicationContext(), SecondScreenActivity.class);
//		 
//        //Sending data to another Activity
//        nextScreen.putExtra("name", "Default Name");
//        nextScreen.putExtra("email", "Default eMail");
//        
//        startActivity(nextScreen);
		
	}
	
	
	@Override
	public void onDetachedFromWindow() {
	}
	
    @Override
    protected void onPause() {
    	finish();
        super.onPause();
        ofApp.pause();
    }

    @Override
    protected void onResume() {
        super.onResume();
        ofApp.resume();
    }
    
    @Override
    public boolean onKeyDown(int keyCode, KeyEvent event) {
	if (OFAndroid.keyDown(keyCode, event)) {
	    return true;
	} else {
	    return super.onKeyDown(keyCode, event);
	}
    }
    
    @Override
    public boolean onKeyUp(int keyCode, KeyEvent event) {
	if (OFAndroid.keyUp(keyCode, event)) {
	    return true;
	} else {
	    return super.onKeyUp(keyCode, event);
	}
    }


	OFAndroid ofApp;
    
	
	@Override
    protected void onDestroy() {
 
       	 Intent i=new Intent();
	   	 i.putExtra("result","Activity_Finished");
	   	 setResult(RESULT_OK,i);     
	  	 finish();
	     super.onDestroy();
  
    }
    public int endApp(){
    	
         Intent i=new Intent();
        
       	 i.putExtra("result","Activity_Finished");
       	 setResult(RESULT_OK,i);     
      	 finish();
         super.onDestroy();
       
   	     return 0;
    } 
	
	
    // Menus
    // http://developer.android.com/guide/topics/ui/menus.html
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
    	// Create settings menu options from here, one by one or infalting an xml
        return super.onCreateOptionsMenu(menu);
    }
    
    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
    	// This passes the menu option string to OF
    	// you can add additional behavior from java modifying this method
    	// but keep the call to OFAndroid so OF is notified of menu events
    	if(OFAndroid.menuItemSelected(item.getItemId())){
    		
    		return true;
    	}
    	return super.onOptionsItemSelected(item);
    }
    

    @Override
    public boolean onPrepareOptionsMenu (Menu menu){
    	// This method is called every time the menu is opened
    	//  you can add or remove menu options from here
    	return  super.onPrepareOptionsMenu(menu);
    }
	
}



