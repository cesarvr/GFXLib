//
//  Vector2.cpp
//  GFXLib
//
//  Created by Cesar Luis Valdez on 04/05/14.
//  Copyright (c) 2014 Cesar Luis Valdez. All rights reserved.
//

#include "vector2.h"


using namespace mlc;


Vector2::Vector2(float _x, float _y): x( _x ), y( _y ){}

void Vector2::operator+= ( const Vector2& vec ){
    this->x += vec.x;
    this->y += vec.y;
}

void Vector2::operator-= ( const Vector2& vec ){
    this->x -= vec.x;
    this->y -= vec.y;
}

void Vector2::operator*= ( const Vector2& vec ){
    this->x *= vec.x;
    this->y *= vec.y;
}

Vector2 Vector2::operator-  ( const Vector2& vec ){
    return Vector2(this->x - vec.x, this->y - vec.y );
}

Vector2 Vector2::operator*  ( const Vector2& vec ){
    return Vector2(this->x * vec.x, this->y * vec.y);
}

Vector2 Vector2::operator*  ( const float& escalar ){
    return Vector2(this->x * escalar, this->y * escalar);
}

void Vector2::operator*= ( const float& escalar ){
    this->x = this->x * escalar;
    this->y = this->y * escalar;
}

float Vector2::magnitud(){
    return  sqrtf( (this->x * this->x) + (this->y * this->y) );
}

void Vector2::normalizar(){
    this->x = this->x / magnitud();
    this->y = this->y / magnitud();
    this->y = this->y / magnitud();
}

Vector2 Vector2::operator/(float scalar){
    
    return Vector2( this->x / scalar, this->y / scalar);
}


float Vector2::dot(const mlc::Vector2 &vec){
    

    return (this->x * vec.x) + (this->y * vec.y);
}

