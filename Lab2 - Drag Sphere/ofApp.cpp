#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
	cam.setDistance(10.0);
	cam.setNearClip(.1);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetBackgroundColor(ofColor::black);
	cam.begin();
	ofSetColor(sphere.color);
	ofNoFill();
	sphere.draw();
	cam.end();
	
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
	glm::vec3 wp = cam.screenToWorld(glm::vec3(x, y, 0));
	glm::vec3 d = glm::normalize(wp - cam.getPosition());

	glm::vec3 p;

	/*if (sphere.intersect(wp, d, p))
		cout << "intersect point: " << p << endl;
	else
		cout << "no intersection" << endl;*/

	plane.pos = sphere.pos;
	plane.normal = cam.getZAxis();

	if (plane.intersect(wp, d, p))
		cout << "plane intersect point: " << p << endl;
	else
		cout << "no intersection" << endl;


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
