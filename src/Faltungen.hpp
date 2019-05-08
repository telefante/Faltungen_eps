//based on
//  TreeRenderer.hpp
//  UmbrisIdearum
//
//  Modified by luis negron on 03.05.19.
//for KLangsondangen für Thomas Kling
//

#ifndef Faltungen_hpp
#define Faltungen_hpp

#include <stdio.h>
#include <ofMain.h>
#include "Tree.hpp"

#define TOTALTREES 3

class Faltungen {
    
public:
    Faltungen();
    void setup();
    void draw();
    void reset(int mode);
    void display();
    
    
    
    //Tree
    vector <Tree> faltungen;
    //vector <Tree> trees;
  //  int total;
    float maxGrowSpeed;
    float minGrowSpeed;
    int minAge;
    int maxAge;
    int bifurcationMax;
    int bifurcationMin;
    
    bool active;
    
    ofFbo fbo;
    int width,heigth;
    
    
    
    
};
#endif /* Faltungen_hpp */
