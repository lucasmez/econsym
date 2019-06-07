#ifndef _NATURE_GOOD_FACTORY_H_
#define _NATURE_GOOD_FACTORY_H_

#include <string>
#include <Good/Factory/IGoodFactory.h>

class NatureGoodFactory: public IGoodFactory {
    public:
        NatureGoodFactory() = default;
        virtual ~NatureGoodFactory() = default;
};

#endif
