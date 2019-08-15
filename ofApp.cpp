#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(2);

}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	auto span = 15;
	for (auto radius = 50; radius < 340; radius += span) {

		auto small_radius = radius;
		auto big_radius = radius + span;

		auto noise_deg = ofMap(ofNoise(radius * 0.005 + ofGetFrameNum() * 0.01), 0, 1, 1, 500);
		if (noise_deg > 360) { noise_deg = 360; }
		vector<glm::vec2> in, out;
		for (auto deg = 0; deg < noise_deg; deg++) {

			in.push_back(glm::vec2(small_radius * cos(deg * DEG_TO_RAD), small_radius * sin(deg * DEG_TO_RAD)));
			out.push_back(glm::vec2(big_radius * cos(deg * DEG_TO_RAD), big_radius * sin(deg * DEG_TO_RAD)));
		}

		reverse(out.begin(), out.end());

		ofSetColor(39);
		ofFill();

		ofBeginShape();
		ofVertices(in);
		ofVertices(out);
		ofEndShape(true);

		vector<glm::vec2> small_circle, big_circle;
		for (auto deg = 0; deg < 360; deg++) {

			small_circle.push_back(glm::vec2(small_radius * cos(deg * DEG_TO_RAD), small_radius * sin(deg * DEG_TO_RAD)));
			big_circle.push_back(glm::vec2(big_radius * cos(deg * DEG_TO_RAD), big_radius * sin(deg * DEG_TO_RAD)));
		}

		ofSetColor(39);
		ofNoFill();

		ofBeginShape();
		ofVertices(small_circle);
		ofEndShape(true);

		ofBeginShape();
		ofVertices(big_circle);
		ofEndShape(true);

		ofSetColor(239);
		ofNoFill();

		ofBeginShape();
		ofVertices(in);
		ofVertices(out);
		ofEndShape(true);
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}