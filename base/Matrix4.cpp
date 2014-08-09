//
//  Matrix4.cpp
//  Block_saga
//
//  Created by Cesar Luis Valdez on 06/08/14.
//  Copyright (c) 2014 Cesar Luis Valdez. All rights reserved.
//

#include "Matrix4.h"
using namespace mlc;


/*
 m11,  m12,  m13, m14,
 m21,  m22,  m23, m24,
 m31,  m32,  m33, m34,
 m41,  m42,  m43, m44;
 
 */

Matrix4::Matrix4(){
    m12 = m13 = m14 = m21 = m23 = m24 = m31 =
    m32 = m34 = m41 = m42 = m43 = 0.0f;
    m11 = m22 = m33 = m44 = 1.0f;
}

Matrix4::Matrix4(float _mt11, float _mt12, float _mt13, float _mt14,
                 float _mt21, float _mt22, float _mt23, float _mt24,
                 float _mt31, float _mt32, float _mt33, float _mt34,
                 float _mt41, float _mt42, float _mt43, float _mt44):

                    m11(_mt11), m12(_mt12), m13(_mt13), m14(_mt14),
                    m21(_mt21), m22(_mt22), m23(_mt23), m24(_mt24),
                    m31(_mt31), m32(_mt32), m33(_mt33), m34(_mt34),
                    m41(_mt41), m42(_mt42), m43(_mt43), m44(_mt44){}



Matrix4 Matrix4::operator+( const Matrix4 &Mat ){
    
    Matrix4 tmp((*this).m11 + Mat.m11, (*this).m12 + Mat.m12, (*this).m13 + Mat.m13,(*this).m14 + Mat.m14,
                (*this).m21 + Mat.m21, (*this).m22 + Mat.m22, (*this).m23 + Mat.m23,(*this).m24 + Mat.m24,
                (*this).m31 + Mat.m31, (*this).m32 + Mat.m32, (*this).m33 + Mat.m33,(*this).m34 + Mat.m34,
                (*this).m41 + Mat.m41, (*this).m42 + Mat.m42, (*this).m33 + Mat.m33,(*this).m44 + Mat.m44 );
                
    
    return tmp;
}

void Matrix4::operator +=( const Matrix4 &Mat ){
    
    m11+= Mat.m11;
    m12+= Mat.m12;
    m13+= Mat.m13;
    m21+= Mat.m21;
    m22+= Mat.m22;
    m23+= Mat.m23;
    m31+= Mat.m31;
    m32+= Mat.m32;
    m33+= Mat.m33;
    m34+= Mat.m34;
    m41+= Mat.m41;
    m42+= Mat.m42;
    m43+= Mat.m43;
    m44+= Mat.m44;
}

Matrix4 Matrix4::operator-( const Matrix4 &Mat ){
    
    Matrix4 tmp((*this).m11 - Mat.m11, (*this).m12 - Mat.m12, (*this).m13 - Mat.m13,(*this).m14 - Mat.m14,
                (*this).m21 - Mat.m21, (*this).m22 - Mat.m22, (*this).m23 - Mat.m23,(*this).m24 - Mat.m24,
                (*this).m31 - Mat.m31, (*this).m32 - Mat.m32, (*this).m33 - Mat.m33,(*this).m34 - Mat.m34,
                (*this).m41 - Mat.m41, (*this).m42 - Mat.m42, (*this).m33 - Mat.m33,(*this).m44 - Mat.m44 );
    
    
    return tmp;
}

void Matrix4::operator -=( const Matrix4 &Mat ){
    
    m11-= Mat.m11;
    m12-= Mat.m12;
    m13-= Mat.m13;
    m21-= Mat.m21;
    m22-= Mat.m22;
    m23-= Mat.m23;
    m31-= Mat.m31;
    m32-= Mat.m32;
    m33-= Mat.m33;
    m34-= Mat.m34;
    m41-= Mat.m41;
    m42-= Mat.m42;
    m43-= Mat.m43;
    m44-= Mat.m44;
}



void Matrix4::operator*=(const Matrix4 &mat){
    
    Matrix4 tmp;
    
    tmp.m11 = m11 * mat.m11 + m12 * mat.m21 + m13 * mat.m31 + m14 * mat.m41;
    tmp.m12 = m11 * mat.m12 + m12 * mat.m22 + m13 * mat.m32 + m14 * mat.m42;
    tmp.m13 = m11 * mat.m13 + m12 * mat.m23 + m13 * mat.m33 + m14 * mat.m43;
    tmp.m14 = m11 * mat.m14 + m12 * mat.m24 + m13 * mat.m34 + m14 * mat.m44;
    
    tmp.m21 = m21 * mat.m11 + m22 * mat.m21 + m23 * mat.m31 + m24 * mat.m41;
    tmp.m22 = m21 * mat.m12 + m22 * mat.m22 + m23 * mat.m32 + m24 * mat.m42;
    tmp.m23 = m21 * mat.m13 + m22 * mat.m23 + m23 * mat.m33 + m24 * mat.m43;
    tmp.m24 = m21 * mat.m14 + m22 * mat.m24 + m23 * mat.m34 + m24 * mat.m44;
    
    tmp.m31 = m31 * mat.m11 + m32 * mat.m21 + m33 * mat.m31 + m34 * mat.m41;
    tmp.m32 = m31 * mat.m12 + m32 * mat.m22 + m33 * mat.m32 + m34 * mat.m42;
    tmp.m33 = m31 * mat.m13 + m32 * mat.m23 + m33 * mat.m33 + m34 * mat.m43;
    tmp.m34 = m31 * mat.m14 + m32 * mat.m24 + m33 * mat.m34 + m34 * mat.m44;
    
    tmp.m41 = m41 * mat.m11 + m42 * mat.m21 + m43 * mat.m31 + m44 * mat.m41;
    tmp.m42 = m41 * mat.m12 + m42 * mat.m22 + m43 * mat.m32 + m44 * mat.m42;
    tmp.m43 = m41 * mat.m13 + m42 * mat.m23 + m43 * mat.m33 + m44 * mat.m43;
    tmp.m44 = m41 * mat.m14 + m42 * mat.m24 + m43 * mat.m34 + m44 * mat.m44;
    
    
    (*this) = tmp;
}

Matrix4 Matrix4::operator*(const mlc::Matrix4 &mat){
    
    Matrix4 tmp;
    
    tmp.m11 = m11 * mat.m11 + m12 * mat.m21 + m13 * mat.m31 + m14 * mat.m41;
    tmp.m12 = m11 * mat.m12 + m12 * mat.m22 + m13 * mat.m32 + m14 * mat.m42;
    tmp.m13 = m11 * mat.m13 + m12 * mat.m23 + m13 * mat.m33 + m14 * mat.m43;
    tmp.m14 = m11 * mat.m14 + m12 * mat.m24 + m13 * mat.m34 + m14 * mat.m44;
    
    tmp.m21 = m21 * mat.m11 + m22 * mat.m21 + m23 * mat.m31 + m24 * mat.m41;
    tmp.m22 = m21 * mat.m12 + m22 * mat.m22 + m23 * mat.m32 + m24 * mat.m42;
    tmp.m23 = m21 * mat.m13 + m22 * mat.m23 + m23 * mat.m33 + m24 * mat.m43;
    tmp.m24 = m21 * mat.m14 + m22 * mat.m24 + m23 * mat.m34 + m24 * mat.m44;
    
    tmp.m31 = m31 * mat.m11 + m32 * mat.m21 + m33 * mat.m31 + m34 * mat.m41;
    tmp.m32 = m31 * mat.m12 + m32 * mat.m22 + m33 * mat.m32 + m34 * mat.m42;
    tmp.m33 = m31 * mat.m13 + m32 * mat.m23 + m33 * mat.m33 + m34 * mat.m43;
    tmp.m34 = m31 * mat.m14 + m32 * mat.m24 + m33 * mat.m34 + m34 * mat.m44;
    
    tmp.m41 = m41 * mat.m11 + m42 * mat.m21 + m43 * mat.m31 + m44 * mat.m41;
    tmp.m42 = m41 * mat.m12 + m42 * mat.m22 + m43 * mat.m32 + m44 * mat.m42;
    tmp.m43 = m41 * mat.m13 + m42 * mat.m23 + m43 * mat.m33 + m44 * mat.m43;
    tmp.m44 = m41 * mat.m14 + m42 * mat.m24 + m43 * mat.m34 + m44 * mat.m44;
    
    
    
    return tmp;
}


Matrix4 Matrix4::translation( Matrix4& mat,  float x, float y, float z){
    Matrix4 tmp;
    
    tmp.m14 = x;
    tmp.m24 = y;
    tmp.m34 = z;
    
    return mat*tmp;
}

/*
 m11,  m12,  m13, m14,
 m21,  cos(m22),  -sin(m23), m24,
 m31,  sin(m32),  cos(m33), m34,
 m41,  m42,  m43, m44;
 
 */


Matrix4 Matrix4::rotateX(mlc::Matrix4 &mat, float rad){
    
    Matrix4 tmp;
    
    
    tmp.m22 = tmp.m33 = cosf(rad);
    tmp.m32 = sinf(rad);
    tmp.m23 = -tmp.m32;

    return mat*tmp;
}


/*
 cos-> m11,  m12,  sin->m13, m14,
       m21,  m22,       m23, m24,
 -sin->m31,  m32,  cos->m33, m34,
       m41,  m42,       m43, m44;
 
 */

Matrix4 Matrix4::rotateY(mlc::Matrix4 &mat, float rad){
    Matrix4 tmp;
    tmp.m11 = tmp.m33 = cosf(rad);
    tmp.m13 = sinf(rad); tmp.m31 = -tmp.m13;

    return  mat*tmp;
}



/*
 cos-> m11,  -sin->m12,
 sin->m21,    cos->m22,
 */

Matrix4 Matrix4::rotateZ(mlc::Matrix4 &mat, float rad){
    Matrix4 tmp;
    tmp.m11 = tmp.m22 = cosf(rad);
    tmp.m21 = sinf(rad); tmp.m12 = -tmp.m21;
    
    return  mat*tmp;
}

/*
 m11,  m12,  m13, m14,
 m21,  m22,  m23, m24,
 m31,  m32,  m33, m34,
 m41,  m42,  m43, m44;
 
 */

Matrix4 Matrix4::makeOrthographic(float left, float right,
                                float bottom, float top,
                                float nearZ, float farZ){

    Matrix4 tmp;
    tmp.m11 = 2.0f / (right-left);
    tmp.m22 = 2.0f / (top-bottom);
    tmp.m33 = -2.0f / (farZ-nearZ);
    tmp.m14 = -(right + left) / (right - left);
    tmp.m24 = -(top + bottom) / (top - bottom);
    tmp.m34 = -(farZ + nearZ) / (farZ - nearZ);
    
    return  tmp;
}





