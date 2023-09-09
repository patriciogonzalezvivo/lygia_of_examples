#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    ofSetVerticalSync(true);
    
    ofDisableArbTex();
    ofLoadImage(tex_danny, "imgs/danny.png");
    ofLoadImage(tex_sprite, "imgs/sprite.png");
    ofLoadImage(tex_moss, "imgs/moss.jpg");
    ofLoadImage(tex_lut, "imgs/lut.png");
    ofLoadImage(tex_noise, "imgs/noise_blue.png");
    tex_moss.setTextureWrap(GL_REPEAT, GL_REPEAT);

    index = 0;
    examples = { "draw_digits.frag", "lighting_atmosphere.frag", "animation_easing.frag","animation_sprite.frag","color_dither.frag","color_lut.frag","color_mix.frag","filter_bilateralBlur2D.frag","filter_boxBlur2D.frag","filter_edge2D.frag","filter_fibonacciBokeh.frag","filter_gaussianBlur2D.frag","filter_kuwahara2D.frag","filter_laplacian2D.frag","filter_median2D.frag","filter_noiseBlur2D.frag","filter_radialBlur2D.frag","filter_sharpen2D.frag","generative_cnoise.frag","generative_curl.frag","generative_fbm.frag","generative_noised.frag","generative_pnoise.frag","generative_random.frag","generative_snoise.frag","generative_voronoi.frag","generative_voronoise.frag","generative_worley.frag","sample_bracketing.frag","sample_untile.frag" };
    shader.load("billboard.vert", examples[index%examples.size()]);

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
        shader.setUniform2f("u_tex0Resolution", tex_danny.getWidth(), tex_danny.getHeight());
    shader.setUniformTexture("u_lut", tex_lut, 1);
    shader.setUniformTexture("u_moss", tex_moss, 2);
    shader.setUniformTexture("u_noise", tex_noise, 3);
    shader.setUniformTexture("u_sprite", tex_sprite, 4);
    shader.setUniform2f("u_spriteResolution", tex_sprite.getWidth(), tex_sprite.getHeight());

    shader.setUniform2f("u_resolution", width, height);
    shader.setUniform2f("u_mouse", (float)ofGetMouseX(), (float)ofGetMouseY());
    shader.setUniform1f("u_time", ofGetElapsedTimef());
    
    ofScale(width*0.5, height*0.5, 1);
    billboard.draw();

    shader.end();
    ofPopMatrix();

    ofDrawBitmapString(examples[index% examples.size()], 5, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == OF_KEY_LEFT || key == OF_KEY_UP)
        index--;
    else
        index++;

    shader.load("billboard.vert", examples[index% examples.size()]);
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
