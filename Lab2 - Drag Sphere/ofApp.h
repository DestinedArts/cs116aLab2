#pragma once

#include "ofMain.h"
#include "glm/gtx/intersect.hpp"

class Sphere {
public:
	glm::vec3 pos = glm::vec3(0, 0, 0);
	ofColor color = ofColor::green;
	float radius = 1.0;
	void draw() {
		ofDrawSphere(pos, radius);
	}
	bool intersect(glm::vec3 p, glm::vec3 d, glm::vec3& intersectPoint) {
		glm::vec3 norm;
		return glm::intersectRaySphere(p, d, pos, radius, intersectPoint, norm);
	}
};

class Plane {
public:
	glm::vec3 pos;
	glm::vec3 normal;
	void draw() {
	}
	bool intersect(glm::vec3 p, glm::vec3 d, glm::vec3& intersectPoint) {
		float dist;
		bool bIntersect = false;
		if (glm::intersectRayPlane(p, d, pos, normal, dist)) {

			// r(t) = o + d * t;  parametric line in vector form
			//
			intersectPoint = p + d * dist;
			bIntersect = true;
		}
		return bIntersect;
	}
};



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

		ofEasyCam cam;

		Sphere sphere;
		Plane plane;
		
};
