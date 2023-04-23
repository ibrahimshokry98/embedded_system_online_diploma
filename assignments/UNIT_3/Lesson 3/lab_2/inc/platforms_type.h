#ifndef PLATFORMS_TYPES_H_
#define PLATFORMS_TYPES_H_



#ifndef _Bool
#define _Bool unsigned char
#endif

typedef _Bool  boolean;

/* unsigned values */

typedef unsigned char          				uint8;
typedef unsigned short         				uint16;
typedef unsigned long          				uint32;
typedef unsigned long long     				uint64;

/* signed values */

typedef signed char          				sint8;
typedef signed short         				sint16;
typedef signed long          				sint32;
typedef signed long long     				sint64;

/* real values */

typedef float 								float32;
typedef double 								float64;

/* volatile types */

typedef volatile signed char				vsint8_t;
typedef volatile unsigned char				vuint8_t;
typedef volatile signed short				vsint16_t;
typedef volatile unsigned short				vuint16_t;
typedef volatile signed long				vsint32_t;
typedef volatile unsigned long				vuint32_t;
typedef volatile signed long long			vsint64_t;
typedef volatile unsigned long long			vuint64_t;

#ifndef FALSE
#define FALSE   ((boolean) 0)
#endif

#ifndef TRUE
#define TRUE   ((boolean) 1)
#endif



#endif