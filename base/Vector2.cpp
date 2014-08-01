//
//  Vector2.cpp
//  GFXLib
//
//  Created by Cesar Luis Valdez on 04/05/14.
//  Copyright (c) 2014 Cesar Luis Valdez. All rights reserved.
//

#include "Vector2.h"


using namespace mlc;


Vector2::Vector2(float _x, float _y): x( _x ), y( _y ){
    
}

void Vector2::operator+= ( const Vector2& vec ){

    this.x += vec.x; 

}
