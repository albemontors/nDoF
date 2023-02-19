#ifndef _ARM_H
#define _ARM_H

#include "definitions.h"
#include "mat.h"
#include "joint.h"
#include "mat.h"
#include "canDevice.h"
#include "jointToMotor.h"

typedef struct {
    u16 qJ;
    Mat4 qC;
    Mat4 qT;
    Mat4 tool; }
CONTROLS;

class Arm{
    public:
        Arm();
        u16 setTool(Mat4 tool);
        Mat4 getTool();
    protected:
        u16 qJ;    //joint quotas
        Mat4 qC;                //cartesian quotas
        Mat4 qT;                //tool quotas
        Mat4 tool;
    private:
        
};

class IdealArm : public Arm {
    public:
        IdealArm();
        void setJointArray(Joint* jointArray);
        u16 update(CONTROLS controls);
        u16 setMovementMode(u16 mode);
        u16 getMovementMode(u16 mode);
    private:
        Joint* J;   //arm joints pointers
        JointToMotor jointToMotor;
        u16 movementmode;
};

class RealArm : public Arm {
    public:
        RealArm();
        void setTransducerArray(Transducer* tArray);
        void setHDArray(Mat4* dhArray);
        CONTROLS update();
    private:
        Mat4* H;    //arm homogeneous transformations link-1 to link
        Transducer* T;
};

#endif