//
//  Quaternion.h
//  GFXLib
//
//  Created by Cesar Luis Valdez on 04/05/14.
//  Copyright (c) 2013 Cesar Luis Valdez. All rights reserved.
//

#ifndef __GFXLib__Quaternion__
#define __GFXLib__Quaternion__

#include <math.h>


namespace mlc {

   class Quaternion {
    public:
        float w, x, y ,z; 
        
    public:
        
        Quaternion(): w(0.0f), x(0.0f) , y(0.0f), z(0.0f) {};
        Quaternion(float w, float x, float y, float z);
		Quaternion conjugate();

	    float magnitud();	
        float dot( const Quaternion& vec );
        void operator*= ( const Quaternion& qa );
      

    };
}


#endif /* defined(__GFXLib__Vector__) */
