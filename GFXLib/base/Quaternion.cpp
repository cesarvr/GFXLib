#include "Quaternion.h"

using namespace mlc; 

Quaternion::Quaternion(): w(0.0f), x(0.0f), y(0.0f), z(0.0f){

}

Quaternion::Quaternion(float _w, float _x, float _y, float _z): w(_w), x(_x), y(_y), z(_z){

}

void Quaternion::operator *= (const Quaternion q){

	Quaternion tmp; 
	tmp.w = w*q.w - x * q.x - y * q.y - z * q.z;
	tmp.x = w*q.x + x * q.w + y * q.z - z * q.y;
	tmp.y = w*q.y - y * q.z + y * q.w + z * q.x; 
	tmp.z = w*q.z + z * q.y - y * q.x + z * q.w;

	*this = tmp;

}
