#ifndef __GFXLib__Vector2__
#define __GFXLib__Vector2__


#include <math.h>
namespace mlc {
	
    class Vector2 {

        public:
            float x, y;
        
            Vector2(): x(0.0f) , y(0.0f){};
            Vector2(float x, float y);
        
            float dot( const Vector2& vec );
            float magnitud();
            void  normalizar();
        
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

