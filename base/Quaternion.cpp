//
//  Quaternion.cpp
//  GFXLib
//
//  Created by Cesar Luis Valdez on 04/05/14.
//  Copyright (c) 2014 Cesar Luis Valdez. All rights reserved.
//

#include "Quaternion.h"


using namespace mlc;


Quaternion::Quaternion(float _w, float _x, float _y, float _z): w( _w ), x( _x ), y( _y ), z( _z ){
       
}



void Quaternion::operator*= ( const Quaternion& qa ){

 	Quaternion tmp;
	tmp.w = (w * qa.w) - (x * qa.x) - (y * qa.y) - (z * qa.z);
	tmp.x = (x * qa.w) + (w * qa.x) + (y * qa.z) - (z * qa.y); 
	tmp.y = (y * qa.w) + (w * qa.y) + (z * qa.x) - (x * qa.z); 
	tmp.z = (z * qa.w) + (w * qa.z) + (x * qa.y) - (y * qa.x); 
	
	(*this) = tmp; 

}

float Quaternion::dot( const Quaternion &q ){
	return ( w * q.w + x*q.x + y*q.y + z*q.z ); 
}


float Quaternion::magnitud (){

	return sqrt(w*w + x*x + y*y + z*z );
}

Quaternion Quaternion::conjugate(){
	
	return Quaternion(w, -x, -y, -z);

}





