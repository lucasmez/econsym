#ifndef _NATURE_GOOD_FACTORY_H_
#define _NATURE_GOOD_FACTORY_H_

#include <string>
#include <Good/Factory/GoodFactory.h>

class NatureGoodFactory: public GoodFactory {
    public:
        NatureGoodFactory() = default;
        virtual ~NatureGoodFactory() = default;
};

#endif
