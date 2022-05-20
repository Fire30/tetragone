#ifndef __ERR_H__
#define __ERR_H__

#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "log.h"

#define CHECK_ERR(err, str)                                                    \
    {                                                                          \
        if (err == -1) {                                                       \
            LOGV("%s: %s", str, strerror(errno));                              \
            exit(errno);                                                       \
        }                                                                      \
    }

#define CHECK_ERR_SLEEP(err, str)                                              \
    {                                                                          \
        if (err == -1) {                                                       \
            LOGV("%s: %s", str, strerror(errno));                              \
            for (;;)                                                           \
                sleep(0x1337);                                                 \
        }                                                                      \
    }

#define ASSERT(cond, str)                                                      \
    {                                                                          \
        if (!(cond)) {                                                         \
            LOGV("%s", str);                                                   \
            exit(errno);                                                       \
        }                                                                      \
    }

#define ASSERT_SLEEP(cond, str)                                                \
    {                                                                          \
        if (!(cond)) {                                                         \
            LOGV("%s", str);                                                   \
            for (;;)                                                           \
                sleep(0x1337);                                                 \
        }                                                                      \
    }

#endif