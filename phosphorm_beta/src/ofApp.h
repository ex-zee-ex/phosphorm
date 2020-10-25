/*
 * Copyright (c) 2013 Dan Wilcox <danomatika@gmail.com>
 *
 * BSD Simplified License.
 * For information on usage and redistribution, and for a DISCLAIMER OF ALL
 * WARRANTIES, see the file, "LICENSE.txt," in this distribution.
 *
 * See https://github.com/danomatika/ofxMidi for documentation
 *
 */
#pragma once

#include "ofMain.h"
#include "ofxMidi.h"

#ifdef TARGET_RASPBERRY_PI 
    #include "ofxOMXVideoGrabber.h"
#endif

class ofApp : public ofBaseApp, public ofxMidiListener {
	
public:
	
	void setup();
	void update();
	void draw();
	void exit();
	
	void keyPressed(int key);
	void keyReleased(int key);
	
	
	
	void newMidiMessage(ofxMidiMessage& eventArgs);
	
	float quantize(float sample, float quantize_amount, float quantize_mix);
	
	void midibiz();
	
	ofxMidiIn midiIn;
	std::vector<ofxMidiMessage> midiMessages;
	std::size_t maxMessages = 10; //< max number of messages to keep track of
	
	
	
	
	void audioOut(ofSoundBuffer & buffer);
    
    
    ofSoundStream soundStream;
    
    float 	pan;
    int		sampleRate;
    bool 	bNoise;
    float 	volume;
    
    vector <float> lAudio;
    vector <float> rAudio;
    
    //this will contain non granularized audio buffer info
    vector <float> lAudio_c;
    vector <float> rAudio_c;
    
    
    
   
    
    //------------------- for the simple sine wave synthesis
    //audio
    float 	phase_l1;
    float 	phaseAdder_l1;
    float 	phaseAdderTarget_l1;
    
    float 	phase_l2;
    float 	phaseAdder_l2;
    float 	phaseAdderTarget_l2;
    
    float 	phase_r1;
    float 	phaseAdder_r1;
    float 	phaseAdderTarget_r1;
   
    float 	phase_r2;
    float 	phaseAdder_r2;
    float 	phaseAdderTarget_r2;
    
    //ampmod
    float 	ampmod_phase_l1;
    float 	ampmod_phaseAdder_l1;
    float 	ampmod_phaseAdderTarget_l1;
    
    float 	ampmod_phase_l2;
    float 	ampmod_phaseAdder_l2;
    float 	ampmod_phaseAdderTarget_l2;
    
    float 	ampmod_phase_r1;
    float 	ampmod_phaseAdder_r1;
    float 	ampmod_phaseAdderTarget_r1;
    
    float 	ampmod_phase_r2;
    float 	ampmod_phaseAdder_r2;
    float 	ampmod_phaseAdderTarget_r2;
    
    //phasemod
    float 	phasemod_phase_l1;
    float 	phasemod_phaseAdder_l1;
    float 	phasemod_phaseAdderTarget_l1;
    
    float 	phasemod_phase_l2;
    float 	phasemod_phaseAdder_l2;
    float 	phasemod_phaseAdderTarget_l2;
    
    float 	phasemod_phase_r1;
    float 	phasemod_phaseAdder_r1;
    float 	phasemod_phaseAdderTarget_r1;
    
    float 	phasemod_phase_r2;
    float 	phasemod_phaseAdder_r2;
    float 	phasemod_phaseAdderTarget_r2;
    
    
    float osc(float arg,float amp, int shape);
   
    
    //for the phosphor styles
    ofFbo fb0;
    ofFbo fb1;
    
    ofShader shader_phosphor;
    
    
};
