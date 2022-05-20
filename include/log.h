#ifndef __LOG_H__
#define __LOG_H__

#include <stdio.h>

#ifdef DEBUG
#define LOGV(...)                                                              \
    {                                                                          \
        printf("[%s:%d: - %s()] ", __FILE__, __LINE__, __FUNCTION__);          \
        printf(__VA_ARGS__);                                                   \
        printf("\n");                                                          \
        fflush(stdout);                                                        \
    }
#else
#define LOGV(...)
#endif
#endif