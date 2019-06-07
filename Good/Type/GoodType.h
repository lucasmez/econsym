#ifndef _GOOD_TYPE_H_
#define _GOOD_TYPE_H_

#include <string>
#include <Common/IPrintable.h>
#include <Good/Common.h>

class GoodType: public IPrintable {
    static good_id currentId;

    protected:
        good_id id;
        std::string name;

    public:
        GoodType(std::string name);
        virtual ~GoodType() = default;

        virtual bool operator==(const GoodType&) const;
        std::string getName() const;
        good_id getId() const;
        virtual std::string str() const override;
        
};

#endif // _GOOD_TYPE_H_