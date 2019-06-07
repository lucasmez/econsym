#ifndef _TIME_EMITTER_H
#define _TIME_EMITTER_H

#include <Common/Types.h>
#include <unistd.h>

class TimeEmitter {
    public:
        template <typename Callback>
        static void in(time_unit inTime, Callback cb) {
            usleep(3000000);
            cb();
        }
};

#endif