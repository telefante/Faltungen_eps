//
//  TreeRenderer.cpp
//  UmbrisIdearum
//
//  Created by luis negron on 03.04.17.
//
//

#include "Faltungen.hpp"

enum MODES {UPDOWN, STAR, EXPLOSION, CHAOS};

Faltungen::Faltungen() {
    /*
     width = ofGetWidth();
     heigth = ofGetHeight();
     fbo.allocate(1920,1080,GL_RGBA32F);
     fbo.begin();
     fbo.clear();
     ofClear(255, 255, 255,255);
     fbo.end();
     */
    
    
    active = false;
    int speedFactor = 5;
    maxGrowSpeed = 1. / speedFactor;
    minGrowSpeed = .5 / speedFactor;
    minAge = 40 * speedFactor;
    maxAge = 120 * speedFactor;
    bifurcationMax = 512*1;
    bifurcationMin = 128*1;
    
    
    
    reset(0);
    
    
}


void Faltungen::reset(int mode) {
    
    faltungen.clear();
    
    int i = mode;
    float offsetX = .1 *ofGetWidth();
    
    switch (i) {
        case 0:
        {
            //arriba
            float step = ofGetWidth() / TOTALTREES;
            for ( int i = 0; i < TOTALTREES; i++ ) {
                float age = ofRandom(minAge, maxAge);
                int limit = floor(ofRandom(bifurcationMin, bifurcationMax));
                ofVec2f thisPos =ofVec2f( i * step + 0 , 0);
                ofVec2f thisVel =  ofVec2f(0, ofRandom(minGrowSpeed, maxGrowSpeed));
                faltungen.push_back(Tree( thisPos + offsetX,thisVel, age, limit, ofColor(0)));
            }
            //Abajo
            /*
             for ( int i = 0; i < TOTALTREES; i++ ) {
             float age = ofRandom(minAge, maxAge);
             int limit = floor(ofRandom(bifurcationMin, bifurcationMax));
             ofVec2f thisPos =ofVec2f( i * step + 0 , ofGetHeight());
             ofVec2f thisVel =  ofVec2f(0, -ofRandom(minGrowSpeed, maxGrowSpeed));
             faltungen.push_back(Tree( thisPos,thisVel, age, limit, ofColor(0)));
             }
             */
        }
            break;
        case 1:
        {
            ofVec2f center = ofVec2f ( ofGetWidth()/2, ofGetHeight()/2);
            float radius = 1;
            float stepRot =  TWO_PI / TOTALTREES;
            for ( int i = 0; i < TOTALTREES; i++ ) {
                float age = ofRandom(minAge, maxAge);
                int limit = floor(ofRandom(bifurcationMin, bifurcationMax));
                ofVec2f thisPos =ofVec2f( radius * cos( i * stepRot )  ,  radius * sin( i * stepRot ) );
                thisPos += center;
                
                ofVec2f thisVel =  center-thisPos;
                thisVel.scale(ofRandom(minGrowSpeed, maxGrowSpeed)*(-1));
                faltungen.push_back(Tree( thisPos,thisVel, age, limit, ofColor(0)));
            }
        }
            break;
            
        case 2:
        {
            ofVec2f center = ofVec2f ( ofGetWidth()/2, ofGetHeight()/2);
            float radius = ofGetHeight()*.5;
            float stepRot =  TWO_PI / TOTALTREES;
            for ( int i = 0; i < TOTALTREES; i++ ) {
                float age = ofRandom(minAge, maxAge);
                int limit = floor(ofRandom(bifurcationMin, bifurcationMax));
                ofVec2f thisPos =ofVec2f( radius * cos( i * stepRot )  ,  radius * sin( i * stepRot ) );
                thisPos += center;
                
                ofVec2f thisVel =  center-thisPos;
                thisVel.scale(ofRandom(minGrowSpeed, maxGrowSpeed)*(1));
                faltungen.push_back(Tree( thisPos,thisVel, age, limit, ofColor(0)));
            }
        }
            break;
            
            
            
    }
    
    
}


void Faltungen::draw() {
    // ofEnableAlphaBlending();
    // fbo.begin();
    
    for(auto & f : faltungen ) {
        f.draw();
    }
    
    //  fbo.end();
    //display();
}

void Faltungen::display() {
    // fbo.draw(0,0);
}
