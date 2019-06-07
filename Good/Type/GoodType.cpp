#include "./GoodType.h"

const std::string GoodType::typeName = "goodtype";
good_id GoodType::currentId = 0;

GoodType::GoodType(std::string name): name{name} {
     id = GoodType::currentId++;
}

bool GoodType::operator==(const GoodType& rhs) const {
    return this->id == rhs.id && this->name == rhs.name;
}

std::string GoodType::getName() const {
    return name;
}

good_id GoodType::getId() const {
    return id;
}

std::string GoodType::str() const {
    return static_cast<std::string>("id: ") + std::to_string(id) + "\tname: " + name;
}