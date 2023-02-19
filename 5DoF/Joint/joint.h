#ifndef _JOINT_H
#define _JOINT_H

#include "mbed.h"
#include "definitions.h"

class Joint{
    public:
        Joint();
        void setParams(J_PARAM params);
        CONTROL_TRIPLET update(CONTROL_TRIPLET control);
        float* getQuotaPointer();
    private:
        u16 maxStroke;
        u16 minStroke;
        u16 maxSpeed;
        u16 maxAcc;
        u16 maxTorque;
        bool homed;
        u16 homeQuota;
        float quota;
        u16 kBitUnit;
};

#endif