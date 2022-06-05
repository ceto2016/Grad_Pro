#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short int u16;
typedef signed short int s16;
typedef unsigned long int u32;
typedef signed long int s32;
typedef float f32;
typedef double f64;
typedef long double f128;

#define STD_TYPES_OK 1
#define STD_TYPES_NOK 0

typedef u8 Std_ReturnType;

typedef struct
{
    u16 vendorID;
    u16 moduleID;
    u8 sw_major_version;
    u8 sw_minor_version;
    u8 sw_patch_version;
} Std_VersionInfoType;

#define NULL ((void *)0)

#endif