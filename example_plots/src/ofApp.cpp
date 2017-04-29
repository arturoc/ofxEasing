#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetBackgroundColor(255);
	ofSetColor(0);

	positions.resize(easings.size());

	initTime = 0;
	endPosition = 90;

	for(size_t i=0;i<easings.size();i++){
		plots[i].setMode(OF_PRIMITIVE_LINE_STRIP);
		for(int x = 0; x < 100; x++){
			auto y = ofxeasing::map(x, 0.f, 100.f, 0.f, 100.f, easings[i]);
			plots[i].addVertex(ofVec3f(x, 100-y)); // invert y to account for OF y grows downwards
		}
	}
}

//--------------------------------------------------------------
void ofApp::update(){
	auto duration = 3.f; // three seconds
	auto now = ofGetElapsedTimef();
	auto endTime = initTime + duration;

	 // Restart the animation one second after finishing
	if(endTime + 1.f < now){
		initTime = ofGetElapsedTimef();
		endTime = initTime + duration;
	}


	for(size_t i=0;i<easings.size();i++){
		positions[i] = ofxeasing::map_clamp(now, initTime, endTime, 0, endPosition, easings[i]);
	}
	// Optionally the back easing equation can receive an extra parameter in the _s functions
	// that controls how much the easing goes forward or backwards
	// positions[4] = ofxeasing::map_clamp(now, initTime, endTime, 0, endPosition, &ofxeasing::back::easeOut_s, 0.8);
}

//--------------------------------------------------------------
void ofApp::draw(){
	auto x = 40;
	auto y = 40;
	auto i = 0;
	for(auto & plot: plots){
		ofPushMatrix();
		ofTranslate(x,y);
		ofDrawRectangle(positions[i], 105, 10, 10);
		ofDrawLine(0, 110, 100, 110);
		plot.draw();
		ofDrawBitmapString(easingNames[i], 0, 130);
		ofDrawLine(0,0,0,100);
		ofDrawLine(0,100,100,100);

		ofPopMatrix();
		x += 140;
		i++;
		if(x+140>ofGetWidth()){
			x = 40;
			y += 200;
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
