//
//  Vector.h
//  GFXLib
//
//  Created by Cesar Luis Valdez on 04/05/14.
//  Copyright (c) 2014 Cesar Luis Valdez. All rights reserved.
//

#ifndef __GFXLib__Vector__
#define __GFXLib__Vector__

#include <iostream>
#include <math.h>
namespace mlc {
class Vector3 {
public:
    float x, y, z;
    
public:
    
    Vector3(): x(0.0f) , y(0.0f), z(0.0f) {};
    Vector3(float x, float y, float z);
    
    Vector3 cross( const Vector3& vec );
    
    float dot( const Vector3& vec );
    float magnitud();
    void  normalizar();
   
    
    void operator+= ( const Vector3& vec );
    void operator-= ( const Vector3& vec );
    void operator*= ( const Vector3& vec );
    Vector3 operator-  ( const Vector3& vec );
    Vector3 operator*  ( const Vector3& vec );
    Vector3 operator*  ( const float& escalar );
    void operator*= ( const float& escalar );
    
    
    
};
}


#endif /* defined(__GFXLib__Vector__) */
