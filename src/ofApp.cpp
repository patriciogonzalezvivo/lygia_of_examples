#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetVerticalSync(true);
    
    ofDisableArbTex();
    ofLoadImage(tex_danny, "danny.png");
    ofLoadImage(tex_sprite, "sprite.png");
    ofLoadImage(tex_moss, "moss.jpg");
    ofLoadImage(tex_lut, "lut.png");

    // shader.load("billboard.vert","draw_digits.frag");
    // shader.load("billboard.vert","animation_easing.frag");
    // shader.load("billboard.vert","animation_sprite.frag");
    // shader.load("billboard.vert","color_dither.frag");
    shader.load("billboard.vert","filter_bilateralBlur2D.frag");

    billboard.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    billboard.addVertex(ofPoint(-1.,-1));
    billboard.addTexCoord(ofVec2f(0.,1.));
    billboard.addColor(ofFloatColor(1.));
    billboard.addVertex(ofPoint(-1.,1));
    billboard.addTexCoord(ofVec2f(0.,0.));
    billboard.addColor(ofFloatColor(1.));
    billboard.addVertex(ofPoint(1.,1));
    billboard.addTexCoord(ofVec2f(1.,0.));
    billboard.addColor(ofFloatColor(1.));
    billboard.addVertex(ofPoint(1.,-1));
    billboard.addTexCoord(ofVec2f(1.,1.));
    billboard.addColor(ofFloatColor(1.));

    ofSetWindowShape(512, 512);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
    float width = ofGetWidth();
    float height = ofGetHeight();
    ofPoint center = ofPoint(width, height) * 0.5;
    
    ofClear(0);
    ofSetColor(255);

    ofPushMatrix();
    ofTranslate(center);
    shader.begin();
    shader.setUniformTexture("u_tex0", tex_danny, 0);
    shader.setUniformTexture("u_lut", tex_lut, 1);
    shader.setUniformTexture("u_moss", tex_moss, 2);
    shader.setUniformTexture("u_sprite", tex_sprite, 3);
    shader.setUniform2f("u_spriteResolution", tex_sprite.getWidth(), tex_sprite.getHeight());

    shader.setUniform2f("u_resolution", width, height);
    shader.setUniform2f("u_mouse", mouseX, mouseY);
    shader.setUniform1f("u_time", ofGetElapsedTimef());

    billboard.draw();

    shader.end();
    ofPopMatrix();

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
