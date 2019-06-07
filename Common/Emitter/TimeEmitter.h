#ifndef _TIME_EMITTER_H
#define _TIME_EMITTER_H

#include <Common/Types.h>
#include <unistd.h>

class TimeEmitter {
    private:
        TimeEmitter() = default;

    public:
        template <typename Callback>
        static void in(time_unit inTime, Callback cb) {
            usleep(1000000 * inTime);
            cb();
        }
};


#endif