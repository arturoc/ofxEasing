#pragma once

#include "ofMain.h"
#include "ofxEasing.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		std::vector<ofxeasing::function> easings{
			ofxeasing::linear::easeIn,
			ofxeasing::quad::easeIn,
			ofxeasing::cubic::easeIn,
			ofxeasing::quart::easeIn,
			ofxeasing::quint::easeIn,
			ofxeasing::circ::easeIn,
			ofxeasing::sine::easeIn,
			ofxeasing::exp::easeIn,
			ofxeasing::elastic::easeOut,
			ofxeasing::bounce::easeOut,
			ofxeasing::back::easeOut,
		};

		std::vector<std::string> easingNames{
			"linear",
			"quad",
			"cubic",
			"quart",
			"quint",
			"circ",
			"sine",
			"exp",
			"elastic",
			"bounce",
			"back",
		};

		std::vector<ofVboMesh> plots{easings.size()};
};
