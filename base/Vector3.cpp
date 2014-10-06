//
//  Vector.cpp
//  GFXLib
//
//  Created by Cesar Luis Valdez on 04/05/14.
//  Copyright (c) 2014 Cesar Luis Valdez. All rights reserved.
//

#include "vector3.h"


using namespace mlc;


Vector3::Vector3(float _x, float _y, float _z): x( _x ), y( _y ), z( _z ){
    
    
}

float Vector3::dot(const Vector3& vec){
    
    return x*vec.x + y*vec.y + z*vec.z;
}

float Vector3::magnitud(){

    return sqrtf( (x * x) + (y * y) + (z * z)  );
}

void Vector3::normalizar(){

    float l = magnitud();
    
    if (l > 0) {
        (*this)*((float)1.0f/l);
    }
    
}


 /*
    Cross Product
  
    fomrula: PxQ = PyQz - PzQy, PzQx - PxQz, PxQy - PyQx
  
    x = PyQz - PzQy
    y = PzQx - PxQz
    z = PxQy - PyQx
  
  
  */


  
Vector3 Vector3::cross(const Vector3& vec ){

    return Vector3( (y * vec.z) - (z * vec.y) , (z*vec.x)-(x*vec.z), (x*vec.y)-(y*vec.x) );
}

void Vector3::operator+= (const Vector3& vec){
    
    x+= vec.x;
    y+= vec.y;
    z+= vec.z;

    
}

void Vector3::operator-= (const Vector3& vec){
    
    x-= vec.x;
    y-= vec.y;
    z-= vec.z;
    
}

Vector3 Vector3::operator- ( const Vector3& vec ){
    
    return Vector3( x-vec.x, y-vec.y, z-vec.z );
    
}


void Vector3::operator*= (const Vector3& vec){
    
    x*= vec.x;
    y*= vec.y;
    z*= vec.z;
    
}

Vector3 Vector3::operator* (const Vector3 &vec){

    return Vector3(x*vec.x, y*vec.y, z*vec.z);

}


void Vector3::operator*= (const float& escalar){
    x*=escalar;
    y*=escalar;
    z*=escalar;
}

Vector3 Vector3::operator* (const float& escalar){
    
  return Vector3(x*escalar, y*escalar, z*escalar);
    
}

    




