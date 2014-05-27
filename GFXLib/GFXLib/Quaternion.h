//
//  Vector.h
//  GFXLib
//
//  Created by Cesar Luis Valdez on 04/05/14.
//  Copyright (c) 2014 Cesar Luis Valdez. All rights reserved.
//

#ifndef __GFXLib__Quaternion__
#define __GFXLib__Quaternion__



namespace mlc {

	class Quaternion{
    public:
        float w, x,y,z;
        
		Quaternion();
		Quaternion(float w, float x, float y ,float z);

		void operator *= (const Quaternion q);


	};


}







#endif /* defined(___GFXLib_Quaternion__) */