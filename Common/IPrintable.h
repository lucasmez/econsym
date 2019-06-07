#ifndef _I_PRINTABLE_
#define _I_PRINTABLE_

#include <iostream>
#include <string>

class IPrintable {
    public:
        virtual std::string str() const = 0;
};

inline std::ostream& operator<<(std::ostream& os, const IPrintable& rhs) {
    os << rhs.str();
    return os;
}

#endif