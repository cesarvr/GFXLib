//
//  Matrix4.h
//  Block_saga
//
//  Created by Cesar Luis Valdez on 06/08/14.
//  Copyright (c) 2014 Cesar Luis Valdez. All rights reserved.
//

#ifndef __Block_saga__Matrix4__
#define __Block_saga__Matrix4__

#include <iostream>

namespace mlc {
    class Matrix4{
        public:
            float   m11,  m12,  m13, m14,
                    m21,  m22,  m23, m24,
                    m31,  m32,  m33, m34,
                    m41,  m42,  m43, m44;

        Matrix4();
        Matrix4(float _mt11, float _mt12, float _mt13, float _mt14,
                float _mt21, float _mt22, float _mt23, float _mt24,
                float _mt31, float _mt32, float _mt33, float _mt34,
                float _mt41, float _mt42, float _mt43, float _mt44);
    
        Matrix4 operator +(  const Matrix4 &Mat );
        void    operator +=( const Matrix4 &Mat );
        Matrix4 operator -(  const Matrix4 &Mat );
        void    operator -=( const Matrix4 &Mat );
        void    operator *=( const Matrix4 &Mat );
        Matrix4 operator * ( const Matrix4 &Mat );
    };
}

#endif /* defined(__Block_saga__Matrix4__) */
