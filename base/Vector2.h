#ifndef __GFXLib__Vector2__
#define __GFXLib__Vector2__

#include <iostream>
#include <math.h>
namespace mlc {
	class Vector2 {

	public:
		float x, y, z;

	    void operator+= ( const Vector2& vec );
        void operator-= ( const Vector2& vec );
        void operator*= ( const Vector2& vec );
        
        Vector2 operator-  ( const Vector2& vec );
        Vector2 operator*  ( const Vector2& vec );
        Vector2 operator*  ( const float& escalar );
        void operator*= ( const float& escalar );

	   
	};
}


#endif /* defined(__GFXLib__Vector__) */

