#ifndef _NATURE_GOOD_TYPE_H_
#define _NATURE_GOOD_TYPE_H_

#include <Good/Type/GoodType.h>

class NatureGoodType: public GoodType {
    public:
        NatureGoodType(std::string name): GoodType {name} {};
        virtual ~NatureGoodType() = default;
        
};

#endif // _NATURE_GOOD_TYPE_H_