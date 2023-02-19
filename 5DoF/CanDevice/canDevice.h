#ifndef _CANDEVICE_H
#define _CANDEVICE_H

#include "definitions.h"
#include <cstdint>

class CanDevice{
    public:
        CanDevice();
    private:
        u16 type;
        u16p canWrite;
        u16p canRead;
};

class Motor : public CanDevice{
    public:
        Motor();
        void setParams(M_PARAM params);
        u16 update();
    private:
        u16 maxSpeed;
        u16 maxAcc;
        u16 maxTorque;
};

class Transducer : public CanDevice {
    public:
        Transducer();
        void setParams(M_PARAM params);
        void update();
        float* getQuotaPointer();
    private:
        float quota;
};

#endif