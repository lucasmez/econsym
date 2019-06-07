#ifndef _I_GOOD_TYPE_H_
#define _I_GOOD_TYPE_H_

#include <string>
#include <Common/IPrintable.h>
#include <Good/Common.h>

class IGoodType: public IPrintable {
    static good_id currentId;

    protected:
        good_id id;
        std::string name;

    public:
        const static std::string typeName;

        IGoodType(std::string name);
        virtual ~IGoodType() = 0;

        virtual bool operator==(const IGoodType&) const;
        std::string getName() const;
        good_id getId() const;
        virtual std::string str() const override;
        
};

#endif // _GOOD_TYPE_H_