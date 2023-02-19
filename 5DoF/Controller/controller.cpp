#include "controller.h"

ArmController::ArmController(){

    // A TON OF GLOBAL VARIABLES
    DH_PARAM DH_param[AXIS_NUMBER];
    J_PARAM J_param[AXIS_NUMBER];
    M_PARAM M_param[AXIS_NUMBER];
    //INIT ALL PARAMETERS
    initGlobalParam(DH_param, J_param, M_param);

    // init joints
    for(int i = 0; i < AXIS_NUMBER; i++)
        J[i].setParams(J_param[i]);

    // init joints
    for(int i = 0; i < AXIS_NUMBER; i++)
        M[i].setParams(M_param[i]);

    // init joints
    for(int i = 0; i < AXIS_NUMBER; i++)
        T[i].setParams(M_param[i]);

    // init denavit hartemberg matrices
    for(int i = 0; i < AXIS_NUMBER; i++)
        DH[i] = Mat4(T[i].getQuotaPointer() , DH_param[i].alpha, DH_param[i].a, DH_param[i].d);

    realArm.setTransducerArray(T);
    realArm.setHDArray(DH);
    idealArm.setJointArray(J);
}

u16 ArmController::update(){
    
    u16 result = idealArm.update(realArm.update());
    
    return result;
}