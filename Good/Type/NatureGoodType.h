#ifndef _NATURE_GOOD_TYPE_H_
#define _NATURE_GOOD_TYPE_H_

#include <Good/Type/GoodType.h>

class NatureGoodType: public GoodType {
    public:
        const static std::string typeName;

        NatureGoodType(std::string name): GoodType {name} {};
        virtual ~NatureGoodType() = default;
        
};

const std::string NatureGoodType::typeName = "naturegoodtype";

#endif // _NATURE_GOOD_TYPE_H_