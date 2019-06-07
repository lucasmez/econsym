#ifndef _TIME_EMITTER_H
#define _TIME_EMITTER_H

class TimeEmitter {
    public:
        template <typename Callback>
        static void in(time_unit inTime, Callback cb) {
            cb();
        }
};

#endif