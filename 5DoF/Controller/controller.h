#ifndef _CONTROLLER_H
#define _CONTROLLER_H

#include "definitions.h"
#include "joint.h"
#include "canDevice.h"
#include "jointToMotor.h"
#include "arm.h"

class ArmController{
    public:
        ArmController();
        u16 update();
    private:
        Joint J[AXIS_NUMBER];
        Motor M[AXIS_NUMBER];
        Mat4 DH[AXIS_NUMBER];
        Transducer T[AXIS_NUMBER];
        JointToMotor jointToMotor;
        RealArm realArm;
        IdealArm idealArm;
        float k;
        Mat4 trackingError;
        DH_PARAM DH_param[AXIS_NUMBER];
        J_PARAM J_param[AXIS_NUMBER];
        M_PARAM M_param[AXIS_NUMBER];
};

#endif