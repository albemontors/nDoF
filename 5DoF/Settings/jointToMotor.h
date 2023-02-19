#ifndef _JOINTTOMOTOR_H
#define _JOINTTOMOTOR_H

#include "definitions.h"
#include "joint.h"
#include "canDevice.h"

class JointToMotor{
    public:
        JointToMotor();
        
    private:
        float proportionalQuotas[AXIS_NUMBER][AXIS_NUMBER];

};

#endif