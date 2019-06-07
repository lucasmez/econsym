#include "./IGoodType.h"

const std::string IGoodType::typeName = "IGoodType";
good_id IGoodType::currentId = 0;

IGoodType::~IGoodType() {}

IGoodType::IGoodType(std::string name): name{name} {
     id = IGoodType::currentId++;
}

bool IGoodType::operator==(const IGoodType& rhs) const {
    return this->id == rhs.id && this->name == rhs.name;
}

std::string IGoodType::getName() const {
    return name;
}

good_id IGoodType::getId() const {
    return id;
}

std::string IGoodType::str() const {
    return static_cast<std::string>("id: ") + std::to_string(id) + "\tname: " + name;
}