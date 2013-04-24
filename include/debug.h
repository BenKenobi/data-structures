#ifndef DEBUG_H_
#define DEBUG_H_

#include <stdio.h>

//#define DEBUG_PRINT_ENABLED   1

#if DEBUG_PRINT_ENABLED
#define DEBUG(fmt...) printf(fmt)
#else
#define DEBUG(fmt...)
#endif

#endif /* DEBUG_H_ */
