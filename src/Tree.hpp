//
//  Tree.hpp
//  UtopiaMaschine
//
//  Created by Luis Negron on 23/01/17.
//
//


#include <stdio.h>
#include <vector>
#include <ofMain.h>

#include "ofxVectorGraphics.h"


#ifndef Tree_hpp
#define Tree_hpp


class Tree {
    
    class Branch {
    public:
        
        Branch() {};
        Branch(ofVec2f _start, ofVec2f _vel, float _timestart, int _generation);
        void setup(ofVec2f _start, ofVec2f _vel, float _timestart, int _generation);
        void render(ofColor clr);
        
        void update();
        bool timetobranch();
        Branch addBranch(float angle);
        
        ofPoint start;
        ofVec2f end;
        ofVec2f vel;
        float alfa;
        int timer;
        float timestart;
        bool growing;
        int myGeneration;
        float thick;
        int maxIterations;
        void setGrow(bool b);
        
    };
    
    
    
public:
    Tree() {};
    
    Tree(ofVec2f _pos, ofVec2f _vel, float _age, int limit, ofColor clr);
    void setup(ofVec2f _pos, ofVec2f _vel, float _age, int limit, ofColor clr);
    void draw();
    
    
    ofVec2f origin, growVel;
    float age;
    
    
    vector <Branch> branches;
    int limitBifurcation;
    bool growing;
    int mode;
    int angleMax, angleMin;
    ofColor myColor;
    
    
    ofxVectorGraphics output;
    bool capture;
    bool bFill;
    
    vector <ofPoint> pts;
};

#endif /* Tree_hpp */
