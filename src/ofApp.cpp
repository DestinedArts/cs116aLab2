#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	cam.setDistance(10.0);
	cam.setNearClip(.1);
	isDragging = false;
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

void printvec3(const char* label, glm::vec3 v)
{
	cout << label << " (" << v[0] << "," << v[1] << "," << v[2] << ")" << endl;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	if (isDragging) {
		glm::vec3 wp = cam.screenToWorld(glm::vec3(x, y, 0)); // convert new mouse position to world coordinates
		glm::vec3 d = wp - mousePos;		// calculate delta in mouse position from when first pressed
		glm::vec3 n = cam.getZAxis();		// view plane normal vector
		glm::vec3 dp = (d - (glm::dot(d,n) / glm::dot(n,n)) * n);	// get the component of d parallel to viewplane
		double drag_scale = glm::distance(cam.getPosition(), spherePos) / glm::distance(cam.getPosition(), mousePos);
		sphere.pos = spherePos + dp * drag_scale;			// Update object's position
		//printvec3("cam", cam.getPosition());
		//printvec3("mxy", glm::vec3(x, y, 0));
		//printvec3("wp", wp);
		//printvec3("d", d);
		//printvec3("n", n);
		//printvec3("dp", dp);
		//printvec3("sph", sphere.pos);
	}
}


//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	glm::vec3 wp = cam.screenToWorld(glm::vec3(x, y, 0));	// convert screen x, y to x, y, z world
	glm::vec3 d = glm::normalize(wp - cam.getPosition());	// convert world to camera x, y
	glm::vec3 p;

	isDragging = sphere.intersect(wp, d, p);

	if (isDragging)
	{
		mousePos = wp;			// save mouse world position
		spherePos = sphere.pos;	// save object world position
		cam.disableMouseInput();
		cout << "intersect point: " << p << endl;
	}
	else
	{
		cam.enableMouseInput();
		mousePos = glm::vec3(0, 0, 0);		// clear mouse position
		cout << "no intersection" << endl;
	}


	plane.pos = sphere.pos;
	plane.normal = cam.getZAxis();

	if (plane.intersect(wp, d, p))
		cout << "plane intersect point: " << p << endl;
	else
		cout << "no intersection" << endl;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	isDragging = false;
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
