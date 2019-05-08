#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    capture = false;
    bFill    = true;
    
    faltungen = Faltungen();
    
    output.setLineWidth(0.75 );
}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(255, 255, 255);
    
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //we don't want to capture every frame
    //so we only capture one frame when capture
    //is set to true
    if(capture){
        output.beginEPS("faltungen.ps");
    }
    
    //faltungen.draw();
    
    
    for(auto & f : faltungen.faltungen ) {
        f.draw();
        for( auto & b : f.branches ) {
            output.line(b.start.x, b.start.y, b.end.x, b.end.y);
            
            
        }
    }
    
    //do we want filled shapes or outlines?
    if(bFill)output.fill();
    else output.noFill();
    ofSetHexColor(0xCC0000);
    
    
    output.endShape(true);
    
    if(capture){
        output.endEPS();
        capture =false;
    }
    
    //
    // End capture!
    //-------------------------
    //-------------------------
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' '){
        capture = true;
    }else if(key =='f'){
        bFill = !bFill;
    }
    
    
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
