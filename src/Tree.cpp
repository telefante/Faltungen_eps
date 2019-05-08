//
//  Tree.cpp
//  UtopiaMaschine
//
//  Created by Luis Negron on 23/01/17.
//
//

#include "Tree.hpp"


Tree::Tree(ofVec2f _pos, ofVec2f _vel, float _age, int limit, ofColor clr) {
    
    origin = _pos;
    growVel = _vel;
    age = _age;
    limitBifurcation = limit;
    branches.reserve(limitBifurcation*4);
    Branch  axiom = Branch(origin, growVel, age, 0);
    branches.push_back(axiom);
    growing = true;
    angleMax = 10;
    angleMin = -10;
    myColor  = clr;
    
}

void Tree::draw() {
    ofEnableAntiAliasing();
    for (auto & b : branches) {
        b.update();
        b.render(myColor);
       
        ofDrawBitmapString(b.myGeneration, b.start.x, b.start.y);
        if ( branches.size() < limitBifurcation) {
            //if(b.myGeneration < 50) {
            if ( b.timetobranch()) {
                int howmany = floor(ofRandom(2, 3));
                for (int j = 0; j < howmany; j++) {
                            branches.push_back(b.addBranch(ofRandom(angleMin, angleMax)));
                }
            }
        }
    }
}

void Tree::Branch::setGrow(bool b) {
    growing = b;
    
}



Tree::Branch::Branch(ofVec2f _start, ofVec2f _vel, float _timestart, int _generation) {
    
    start = _start;
    end = start;
    vel = _vel;
    
    myGeneration = _generation;
    timer = _timestart;
    timestart =timer;
    growing = true;
    
    alfa = 255;
    //thick = 4.;
    
    thick = 3. - (myGeneration * .15);
    if (thick < .3f) {
        thick = .3f;
    }
    
    alfa = 1.;
    /*alfa = 1. - (myGeneration * .01);
				if (alfa < .1) {
                    alfa = .1;
                }
    */
    
    
    
}


Tree::Branch Tree::Branch ::addBranch(float f) {
    float theta = atan2(vel.y,vel.x);
    theta += ofDegToRad(f);
    float mag = vel.length()*ofRandom(.8,1.2);
    ofVec2f newVel = ofVec2f(mag * cos(theta), mag * sin(theta));
   
    return Branch(end, newVel, timestart * .99 , myGeneration+1);
}

void Tree::Branch::update() {
    // timer -= 1;
    
    // cout << timer;
    if(growing) {
        end += vel;
        //cout << "A";
    }
    
    
}

void Tree::Branch::render(ofColor clr) {
    
    //  ofSetColor(100);
    //ofDrawBitmapString(end.y, end.x, end.y- 20 );
    // ofSetColor(0, 0, 0, alfa*255);
    //    ofSetColor(gray,gray,gray, alfa*255);
    int trp = (int) (alfa *255.);
    ofSetColor(clr, trp);
    ofSetLineWidth(thick);
    ofDrawLine(start.x,start.y, end.x, end.y);
    
}


bool Tree::Branch::timetobranch() {
    timer--;
    //  cout << timer;
    if (timer < 0 && growing) {
        growing = false;
        return true;
    } else {
        return false;
    }
}
