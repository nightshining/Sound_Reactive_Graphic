#pragma once

#include "ofMain.h"
#include "ofxMidi.h"
#include "ofxTween.h"

class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void exit();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    
    ofxMidiOut midiOut;
    ofxTween tween;
    ofxEasingElastic easing;
    
    int channel;
	
	unsigned int currentPgm;
	int note, note2, velocity, pan, bend, touch, polytouch, radius;
    float tempo, speed, counter;
    
    vector<int>tones;
    
    bool c;
    ofColor colorChange;
    ofPoint pos;
    
    
};
