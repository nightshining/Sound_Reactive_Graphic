#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetCircleResolution(50);
    ofSetFrameRate(60);
	ofSetLogLevel(OF_LOG_VERBOSE);
    ofSetWindowTitle("Sound_Reactive_Graphic");
	
	pos.set(ofGetWidth() / 2, ofGetHeight() / 2);
    
	midiOut.openPort(0);	    
	
	channel = 1;
	currentPgm = 0;
	note = 0;
    note2 = 0;
	velocity = 1;
	pan = 0;
	bend = 0;
	touch = 0;
	polytouch = 0;
    radius = 50;
    
    colorChange = ofColor::crimson;
    
    tween.setParameters(1, easing, ofxTween::easeInOut, 20, 50, 1000, 100);
    
    for (int i = 0; i < 126; i++){ 
        
    tones.push_back(i);
        
    }
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    radius = tween.update();
    
   

}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    
    ofBackgroundGradient(ofColor::whiteSmoke, ofColor::gray, OF_GRADIENT_LINEAR);
   
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofSetColor(colorChange);
    ofFill();
    ofCircle(0, 0, radius);
    
    ofSetColor(ofColor::black);
    ofNoFill();
    ofCircle(0, 0, radius);
    ofPopMatrix();
    
    ofDrawBitmapString("Tap bubble to generate random tones", pos + radius);
    ofDrawBitmapString("Drag bubble to change parameters", pos + radius + 20);
    
}

void testApp::exit() {
	
	// clean up
	midiOut.closePort();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
    
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
    pos.x = x;
    pos.y = y;
    
    midiOut.sendControlChange(channel, 7, ofMap(y, 0, ofGetHeight(), 0, 127));
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

    
    int dist1 = ofDist(pos.x, pos.y, x, y);
    
    if ( dist1 < radius ) {

        colorChange = ofColor::whiteSmoke;
        midiOut.sendNoteOn(channel, tones[ofRandom(127)]);
        
    }
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
    int dist1 = ofDist(pos.x, pos.y, x, y);
    
    if ( dist1 < radius ) {
        
        colorChange = ofColor::crimson;
        midiOut.sendNoteOff(channel, tones[ofRandom(127)]);

    }
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
    
}
