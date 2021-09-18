//----------------------------------------------------------------------------------------------------------------------------
// 1) ALLOW MULTIPLE INCLUSION OF THIS HEADER FILE
//----------------------------------------------------------------------------------------------------------------------------
#ifndef DATATYPES_H
#define DATATYPES_H

//----------------------------------------------------------------------------------------------------------------------------
// 2) NO INCLUDE FILES INSIDE HEADERS ALLOWED
//----------------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------------
// 3) DECLARATIONS OF GLOBAL DATA STRUCTURES AND ENUMS AND NEW TYPES
//----------------------------------------------------------------------------------------------------------------------------

// For portability, the basic numerical types of signed and unsigned variants of char, int, short, long, float, and double
// shall not be used, but instead the following specific length typedefs:

#ifndef STM8_DATA_TYPES
#define STM8_DATA_TYPES

typedef unsigned char       bool;       //!< boolean type e.g. in return types of Functions

typedef unsigned int        bf;         //!< bit field e.g. in "struct{ bf bMyFlag :1; ... }"

typedef signed char         int8;       //!< signed 8-bit integer -128 ... 127
typedef unsigned char       uint8;      //!< unsigned 8-bit integer 0 ... 255

typedef signed   int        int16;      //!< signed 16-bit integer -32768 ... 32767
typedef signed   long       int32;      //!< signed 32-bit integer -2147483648 ... 2147483647

typedef unsigned int        uint16;     //!< unsigned 16-bit integer 0 ... 65536
typedef unsigned long       uint32;     //!< unsigned 32-bit integer 0 ... 4294967296

typedef float               float32;    //!< 32-bit floating point type
typedef long double         float64;    //!< 63-bit floating point type

#define FALSE               0           //!< Symbolic constant for boolean types
#define TRUE                1           //!< Symbolic constant for boolean types

#endif

//----------------------------------------------------------------------------------------------------------------------------
// 4) EXTERN DECLARATIONS OF GLOBAL VARIABLES, ARRAYS AND STRUCTS 
//----------------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------------
// 5) EXTERN DECLARATIONS OF GLOBAL FUNCTION PROTOTYPES
//----------------------------------------------------------------------------------------------------------------------------

#endif // DATATYPES_H

// EOF, no more
