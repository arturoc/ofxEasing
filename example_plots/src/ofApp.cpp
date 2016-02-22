#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//ofSetBackgroundColor(255);
	ofSetColor(0);
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

}

//--------------------------------------------------------------
void ofApp::draw(){
	auto x = 40;
	auto y = 40;
	auto i = 0;
	for(auto & plot: plots){
		ofPushMatrix();
		ofTranslate(x,y);
		plot.draw();
		ofDrawBitmapString(easingNames[i], 0, 120);
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
