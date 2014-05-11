//
//  main.cpp
//  GFXLib
//
//  Created by Cesar Luis Valdez on 04/05/14.
//  Copyright (c) 2014 Cesar Luis Valdez. All rights reserved.
//

#include <iostream>
#include "Vector.h"
#include "Matrix3.h"


using namespace mlc;

void prueba1(){

    
    Vector3 vector1(1.0f,  2.0f, 3.0f);
    Vector3 vector2(2.0f, -2.0f, 3.0f);
    
    vector1+=vector2;
    vector1 * 3;
    
    std::cout << "x: " << vector1.x << " y: " << vector1.y << " z: " << vector1.z << std::endl;
    
    
    Vector3 cross = vector1.cross(vector2);
    
    std::cout << " cross x: " << cross.x << " y: " << cross.y << " z: " << cross.z << std::endl;
    
    float producto_escalar =  cross.dot(vector1);
    
    
    std::cout << " dot of cross: " << producto_escalar << std::endl;
    std::cout << " len of cross: " << cross.magnitud() << std::endl;
    
    
    Vector3 vec(1.0f,  2.0f, 3.0f);
    
    
    std::cout << "vec1 x: " << vec.x << " y: " << vec.y << " z: " << vec.z << std::endl;
    
    vec.normalizar();
    
    std::cout << "vec1 unidad x: " << vec.x << " y: " << vec.y << " z: " << vec.z << std::endl;

}

void prueba2(){

    Vector3 P(1.0f, 2.0f, 3.0f);
    Vector3 Q(2.0f, 1.5f, 4.0f);
    Vector3 R(1.0f, 2.5f, 0.5f);
    std::cout << "inicio " << std::endl;
    std::cout << "P: " << P.x << " y: " << P.y << " z: " << P.z << std::endl;
    std::cout << "Q: " << Q.x << " y: " << Q.y << " z: " << Q.z << std::endl;
    std::cout << "R: " << R.x << " y: " << R.y << " z: " << R.z << std::endl;
    
    
    
    Vector3 res = P.cross(Q);
    
    float d = res.dot(Q);
    std::cout << "dot: " << d << std::endl;
    res = res.cross(R);
    
    std::cout << "PxQxR x: " << res.x << " y: " << res.y << " z: " << res.z << std::endl;
    
    
    
    
    float PRd = P.dot(R);
    std::cout << "(P.R): " << PRd << std::endl << std::endl;
    Vector3 res_PRQ = Q * PRd;
    std::cout << "(P.R)Q: x:" << res_PRQ.x << " y: " << res_PRQ.y << " z: " << res_PRQ.z << std::endl;
    
    
    float QRd = Q.dot(R);
    std::cout << " (Q.R): " << QRd << std::endl << std::endl;

    Vector3 res_QRP = P * QRd;
    
    std::cout << "(Q.R)P: x: " << res_QRP.x << " y: " << res_QRP.y << " z: " << res_QRP.z << std::endl;

    
    Vector3 PRQ_QRP = res_PRQ - res_QRP;
    
    std::cout << "(P.R)Q - (Q.R)P: x:" << PRQ_QRP.x << " y: " << PRQ_QRP.y << " z: " << PRQ_QRP.z << std::endl;
    

    
    
    
    std::cout << "P: " << P.x << " y: " << P.y << " z: " << P.z << std::endl;
    std::cout << "Q: " << Q.x << " y: " << Q.y << " z: " << Q.z << std::endl;
    std::cout << "R: " << R.x << " y: " << R.y << " z: " << R.z << std::endl;
    
}

void cross_test(){

    Vector3 P(1.0f, 2.0f, 3.0f);
    Vector3 Q(2.0f, 1.5f, 4.0f);
    Vector3 R(1.0f, 2.5f, 0.5f);
    std::cout << "inicio " << std::endl;
    std::cout << "P: x:" << P.x << " y: " << P.y << " z: " << P.z << std::endl;
    std::cout << "Q: x:" << Q.x << " y: " << Q.y << " z: " << Q.z << std::endl;
    std::cout << "R: x:" << R.x << " y: " << R.y << " z: " << R.z << std::endl;
    
    
    
    Vector3 cross = P.cross(Q);
    
    float d = cross.dot(Q);
    std::cout << "CROSS x: " << cross.x << " y: " << cross.y << " z: " << cross.z << std::endl;
    
    std::cout << "dot: " << d << std::endl;



}

void showMat(const Matrix3 mat){
    std::cout << " " << std::endl;
    std::cout.precision(4);
    std::cout << mat.m11 << " " << mat.m12 << " " << mat.m13 << std::fixed<< std::endl;
    std::cout << mat.m21 << " " << mat.m22 << " " << mat.m23 << std::endl;
    std::cout << mat.m31 << " " << mat.m32 << " " << mat.m33 << std::endl;
    std::cout << " " << std::endl;
    
/*    printf("\n\n%f %f %f \n", mat.m11,mat.m12,mat.m13 );
    printf("%f %f %f \n", mat.m21,mat.m22,mat.m23 );
    printf("%f %f %f \n\n", mat.m31,mat.m32,mat.m33 );
  */
}

void test_mat_add(){
    
    Matrix3 mtx1, mtx2;
    mtx1 += mtx2;
    
    showMat(mtx1);
    
    
    
    mtx1 -= mtx2;
    showMat(mtx1);
    

    
    Matrix3 mtx3(4.0f, 2.0f, 3.0f,
                 2.0f, 4.0f, 1.0f,
                 3.0f, 2.0f, 1.0f);
    
    mtx3 *= mtx1;
    
    
    showMat(mtx3);
    
    
    std::cout << "mtx3.Determinant: "<< mtx3.getDeterminant() << std::endl;
    
    std::cout << "inverse" << std::endl;
    
    Matrix3 m = mtx3.inverse();
    
    showMat(m );
    
    
    std::cout << "inverse proof" << std::endl;
    
    mtx3 *= m ;
    
    showMat(mtx3);
   
    
}

int main(int argc, const char * argv[])
{
    //cross_test();
    //prueba2();
    test_mat_add();
 
    
    return 0;
}

