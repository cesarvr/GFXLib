//
//  Matrix3.cpp
//  GFXLib
//
//  Created by Cesar Luis Valdez on 11/05/14.
//  Copyright (c) 2014 Cesar Luis Valdez. All rights reserved.
//

#include "matrix3.h"

using namespace mlc;

/*
 
        m11,  m12,  m13,
        m21,  m22,  m23,
        m31,  m32,  m33;
 
 */


Matrix3::Matrix3(){
    
    m21 = m31 = m12 = m32 = m13 = m23 = 0.0f;
    m11 = m22 = m33 = 1.0f;
    
}

Matrix3::Matrix3(

                 float mt01, float mt02, float mt03,
                 float mt04, float mt05, float mt06,
                 float mt07, float mt08, float mt09
              
                 ):  m11(mt01), m22(mt05), m33(mt09), 
                     m21(mt04), m31(mt07), m12(mt02), 
                     m32(mt08), m13(mt03), m23(mt06) {

}

Matrix3 Matrix3::operator+( const Matrix3 &Mat ){

    Matrix3 tmp((*this).m11 + Mat.m11, (*this).m12 + Mat.m12, (*this).m13 + Mat.m13,
                (*this).m21 + Mat.m21, (*this).m21 + Mat.m21, (*this).m23 + Mat.m23,
                (*this).m21 + Mat.m21, (*this).m31 + Mat.m31, (*this).m33 + Mat.m33);

    return tmp;
}

void Matrix3::operator +=( const Matrix3 &Mat ){
    
    m11+= Mat.m11;
    m12+= Mat.m12;
    m13+= Mat.m13;
    m21+= Mat.m21;
    m22+= Mat.m22;
    m23+= Mat.m23;
    m31+= Mat.m31;
    m32+= Mat.m32;
    m33+= Mat.m33;

}

Matrix3 Matrix3::operator-( const Matrix3 &Mat ){
    
    Matrix3 tmp((*this).m11 - Mat.m11,  (*this).m12 - Mat.m12,  (*this).m13 - Mat.m13,
                (*this).m21 - Mat.m21,  (*this).m21 - Mat.m21,  (*this).m23 - Mat.m23,
                (*this).m21 - Mat.m21,  (*this).m31 - Mat.m31,  (*this).m33 - Mat.m33);
    
    return tmp;
    
}

void Matrix3::operator -=( const Matrix3 &Mat ){
    
    m11-= Mat.m11;
    m12-= Mat.m12;
    m13-= Mat.m13;
    m21-= Mat.m21;
    m22-= Mat.m22;
    m23-= Mat.m23;
    m31-= Mat.m31;
    m32-= Mat.m32;
    m33-= Mat.m33;
}




void Matrix3::operator*=(const Matrix3 &mat){

    float tmp[9];
    
    
    tmp[0] = m11 * mat.m11 +  m12 * mat.m21 +  m13 * mat.m31;
    tmp[1] = m12 * mat.m11 +  m22 * mat.m21 +  m23 * mat.m31;
    tmp[2] = m13 * mat.m11 +  m32 * mat.m21 +  m33 * mat.m31;
    
    tmp[3] = m11 * mat.m12 +  m12 * mat.m22 +  m13 * mat.m32;
    tmp[4] = m21 * mat.m12 +  m22 * mat.m22 +  m23 * mat.m32;
    tmp[5] = m31 * mat.m12 +  m32 * mat.m22 +  m33 * mat.m32;
    
    tmp[6] = m11 * mat.m13 +  m12 * mat.m23 +  m13 * mat.m33;
    tmp[7] = m21 * mat.m13 +  m22 * mat.m23 +  m23 * mat.m33;
    tmp[8] = m31 * mat.m13 +  m32 * mat.m23 +  m33 * mat.m33;

    (*this) = Matrix3( tmp[0],tmp[1],tmp[2], tmp[3],tmp[4],tmp[5], tmp[6],tmp[7],tmp[8]  );
}

Matrix3 Matrix3::operator*(const Matrix3 &mat){

    float tmp[9];
    
    
    tmp[0] = m11 * mat.m11 +  m12 * mat.m21 +  m13 * mat.m31;
    tmp[1] = m12 * mat.m11 +  m22 * mat.m21 +  m23 * mat.m31;
    tmp[2] = m13 * mat.m11 +  m32 * mat.m21 +  m33 * mat.m31;
    
    tmp[3] = m11 * mat.m12 +  m12 * mat.m22 +  m13 * mat.m32;
    tmp[4] = m21 * mat.m12 +  m22 * mat.m22 +  m23 * mat.m32;
    tmp[5] = m31 * mat.m12 +  m32 * mat.m22 +  m33 * mat.m32;
    
    tmp[6] = m11 * mat.m13 +  m12 * mat.m23 +  m13 * mat.m33;
    tmp[7] = m21 * mat.m13 +  m22 * mat.m23 +  m23 * mat.m33;
    tmp[8] = m31 * mat.m13 +  m32 * mat.m23 +  m33 * mat.m33;
    
    return  Matrix3( tmp[0],tmp[1],tmp[2], tmp[3],tmp[4],tmp[5], tmp[6],tmp[7],tmp[8]  );

}




float Matrix3::determinant(){


    return ((m11*((m22*m33)-(m23*m32)))- (m12 *((m21*m33)-(m23*m31)))) + (m13 * ((m21*m32)-(m22*m31)))  ;
}



/*
    Division por escalar

 */

void Matrix3::operator/(const float escalar){
    
    m11/=escalar;
    m12/=escalar;
    m13/=escalar;
    m21/=escalar;
    m22/=escalar;
    m23/=escalar;
    m31/=escalar;
    m32/=escalar;
    m33/=escalar;
    
}



Matrix3 Matrix3::inverse(){

    float det = (*this).determinant();
    
    
    Matrix3 tmp( (m23*m32)-(m22*m33), (m12*m33)-(m13*m32), (m13*m22)-(m12*m23),
                 (m21*m33)-(m23*m31), (m13*m31)-(m11*m33), (m11*m23)-(m13*m21),
                 (m22*m31)-(m21*m32), (m11*m32)-(m12*m31), (m12*m21)-(m11*m22) ) ;

    
    tmp / det;

    return tmp;
}


Matrix3 Matrix3::transpose(){

    /*
     
     m11,  m12,  m13,
     m21,  m22,  m23,
     m31,  m32,  m33;
     
     */


    return Matrix3(m11, m21, m31,
                   m12, m22, m32,
                   m13, m23, m33);
}


