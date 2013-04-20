#ifndef DEBUG_H_
#define DEBUG_H_

#include <stdio.h>

#define DEBUG_PRINT_ENABLED   1

#if DEBUG_PRINT_ENABLED
#define DEBUG printf
#else
#define DEBUG(format, args...) ((void)0)
#endif

#endif /* DEBUG_H_ */
