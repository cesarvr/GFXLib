//
//  Matrix3.h
//  GFXLib
//
//  Created by Cesar Luis Valdez on 11/05/14.
//  Copyright (c) 2014 Cesar Luis Valdez. All rights reserved.
//

#ifndef __GFXLib__Matrix3__
#define __GFXLib__Matrix3__


#include <math.h>

namespace mlc{
    

class Matrix3 {
public:
    
    float m11,  m12,  m13,
          m21,  m22,  m23,
          m31,  m32,  m33;
    
public:
    
    Matrix3();
    Matrix3( float mt01, float mt02, float mt03,
             float mt04, float mt05, float mt06,
             float mt07, float mt08, float mt09 );
   
    float determinant();
    
    Matrix3 transpose();
    Matrix3 inverse();
    Matrix3 operator-(const Matrix3 &mtx);
    Matrix3 operator+(const Matrix3 &mtx);
    Matrix3 operator*(const Matrix3 &mtx);
    
    
    
    void    operator+=(const Matrix3 &mtx);
    void    operator-=(const Matrix3 &mtx);
    void    operator*=(const Matrix3 &mtx);
    
    
    
    void operator/(const float escalar);
    
    
    
};
    
    
}
#endif /* defined(__GFXLib__Matrix3__) */
