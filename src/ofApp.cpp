#include "ofApp.h"
#include "ofxAndroidApp.h"
#include <jni.h>


//====================================================================================================
/**
 *  Communication between Java and Openframeworks, useful for calling native methods (call C++ into Java)
 *	This is a method without parameters , if you want to pass (for example) an 'int' the code would be:
 *	Java_cc_openframeworks_activitiesOF_OFActivity_callCmethod(JNIEnv *, jobject, jint foo)
 *	For more Primitive Types and Native Types see:
 *  http://docs.oracle.com/javase/7/docs/technotes/guides/jni/spec/types.html
 */

extern "C"{
JNIEXPORT void JNICALL
Java_cc_openframeworks_activitiesOF_OFActivity_callCmethod(JNIEnv *, jobject){


		/**
		 * This code runs when "callCmethod" function is called in OFActivity.java (Java side)
		 */

		ofLog() << "C++ Method called from Java" << endl;
	}
}

//=====================================================================================================

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetVerticalSync(true);

	changeActivity.addListener(this, &ofApp::changeActivityPressed);

	//ofxGuiSetFont("Questrial-Regular.ttf",18,true,true);
	ofxGuiSetTextPadding(20);
	ofxGuiSetDefaultWidth(300);
	ofxGuiSetDefaultHeight(40);

	gui.setup("panel");
	gui.add(changeActivity.setup("changeActivity", 200, 200));

	/**
	 * This methods setup Java class and Java object-class that allow to call Java methods (OFActivity.java) in Openframeworks (ofApp.cpp)
	 */
	setupJNI();

}
//-------------------------------------------------------------
void ofApp::changeActivityPressed(){

	JNIEnv *env = ofGetJNIEnv();

	/**
	 * This calls the "openActivity" java-method, it's a "void" function without parameters.
	 *
	 */
	jmethodID javaReturnMethod = env->GetMethodID(javaClass,"openActivity","()V");
	if(!javaReturnMethod){
		ofLog() << "Method NOT found!" << endl;
	}else if(javaReturnMethod){
		ofLog() << "Method found!" << endl;
	}

	//This code execute Java method located in OFActivity.java
	env->CallVoidMethod(javaObject, javaReturnMethod);

	//Code that close actual OFActivity and give feedback to the activity change (coded in OFActivity.java)
	endApp();

}
//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofBackgroundGradient(ofColor::white, ofColor::gray);

	gui.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){ 
	
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){ 
	
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::touchDown(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::touchMoved(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::touchUp(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::touchDoubleTap(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::touchCancelled(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::swipe(ofxAndroidSwipeDir swipeDir, int id){

}

//--------------------------------------------------------------
void ofApp::pause(){
	ofExit(0);
}

//--------------------------------------------------------------
void ofApp::stop(){
	ofExit(0);
}

//--------------------------------------------------------------
void ofApp::resume(){
	ofSetVerticalSync(true);

		changeActivity.addListener(this, &ofApp::changeActivityPressed);

		//ofxGuiSetFont("Questrial-Regular.ttf",18,true,true);
		ofxGuiSetTextPadding(20);
		ofxGuiSetDefaultWidth(300);
		ofxGuiSetDefaultHeight(40);

		gui.setup("panel");
		gui.add(changeActivity.setup("changeActivity", 100, 100));
}

//--------------------------------------------------------------
void ofApp::reloadTextures(){

}

//--------------------------------------------------------------
bool ofApp::backPressed(){
	ofExit(0);
	return false;
}

//--------------------------------------------------------------
void ofApp::okPressed(){

}

//--------------------------------------------------------------
void ofApp::cancelPressed(){

}
//---------------------------------------------------------------
void ofApp::endApp(){

	ofExit(0);
}
//---------------------------------------------------------------
void ofApp::setupJNI(){

	JNIEnv *env = ofGetJNIEnv();

	//get OFActivity class from java
	jclass localClass = env->FindClass("cc/openframeworks/activitiesOF/OFActivity");
	javaClass = (jclass) env->NewGlobalRef(localClass);
	if (!javaClass) {
		ofLog() << "javaClass NOT found!" << endl;
	}else if(javaClass){
		ofLog() << "javaClass found!" << endl;
	}

	//get OFActiviy object from java
	javaObject = ofGetOFActivityObject();
	javaObject = (jobject) env->NewGlobalRef(javaObject);
	if (!javaObject) {
		ofLog() << "javaObject NOT found!" << endl;
	}else if(javaObject) {
		ofLog() << "javaObject found!" << endl;
	}
}
