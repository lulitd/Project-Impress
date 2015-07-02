#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	displayWidth=ofGetWindowWidth();
	displayHeight=ofGetWindowHeight();
	colNum=6;
	rowNum=12;

	imgWidth=displayWidth*1.0/colNum;
	imgHeight=displayHeight*1.0/rowNum;

	locations.reserve((colNum+1)*rowNum);
	status.reserve((colNum+1)*rowNum);
	for (float f=0; f<displayHeight; f=f+imgHeight){
		for (float g=0; g<displayWidth; g=g+imgWidth){
			locations.push_back( ofPoint(g,f));

			/* determine what type each location is based on location in grid 3x2
			 * upper left is 0
			 * upper right is 1 
			 * down left is 2
			 *down right is 3
			 *middle column is 4
			*/
			if (g+imgWidth/2<=ofGetWindowWidth()/3 && f+imgHeight/2<ofGetWindowHeight()/2){
				status.push_back('0');
			}
			else if (g+imgWidth/2>=ofGetWindowWidth()/3*2 && f+imgHeight/2<ofGetWindowHeight()/2){
				status.push_back('1');
			}
			else if (g+imgWidth/2<=ofGetWindowWidth()/3 && f+imgHeight/2>ofGetWindowHeight()/2){
				status.push_back('2');
			}
			else if (g+imgWidth/2>=ofGetWindowWidth()/3*2 && f+imgHeight/2>ofGetWindowHeight()/2){
				status.push_back('3');
			} else {
				status.push_back('4');
			}
	}
	}


}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(ofColor::black);
	ofColor c= ofColor::black;
	string s="";
	for( int i=0; i<locations.size(); i++){
		switch(status[i]){
		case '0': c=ofColor::aqua;
			s="0";
			break;
		case '1': c=ofColor::greenYellow;
			s="1";
			break;
		case '2': c=ofColor::blueSteel;
			s="2";
			break;
		case '3': c=ofColor::mediumPurple;
			s="3";
			break;
		case '4': c=ofColor::orange;
			s="4";
			break;
		}
		ofSetColor(c);
		ofFill();
		ofRect(locations[i].x,locations[i].y,imgWidth,imgHeight);
		ofSetColor(255);
		ofNoFill();
		ofRect(locations[i].x,locations[i].y,imgWidth,imgHeight);
		ofSetColor(0);
		ofDrawBitmapString(s,locations[i].x,locations[i].y);
		ofSetColor(ofColor::red);
		ofFill();
		ofCircle(locations[i].x,locations[i].y,10);
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
