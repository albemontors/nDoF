#ifndef _DEFINITION_H
#define _DEFINITION_H

#include "mbed.h"
#include "params.h"
#include <cstdint>

typedef uint16_t u16;
typedef uint16_t* u16p;

typedef struct { 
    u16 x;
    u16 y;
    u16 z; }
VECTOR3D;

typedef struct { 
    float x;
    float y;
    float z; }
VECTOR3Df;

typedef struct {
    u16 x;
    u16 y;
    u16 z;
    u16 a;
    u16 b;
    u16 c; }
VECTOR6D;

typedef struct {
    float x;
    float y;
    float z;
    float a;
    float b;
    float c; }
VECTOR6Df;

typedef struct {
    u16 J1;
    u16 J2;
    u16 J3;
    u16 J4;
    u16 J5; } 
POSE;

typedef struct {
    u16 controlSpeed;
    u16 controlVel;
    u16 torqueFF; }
CONTROL_TRIPLET;


#endif