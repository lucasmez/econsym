#include <algorithm>
#include "./GoodsManager.h"

GoodType* GoodsManager::getGoodType(good_id id) const {
    auto found = std::find_if(types.cbegin(), types.cend(), [&id](const GoodType* type){
        return type->getId() == id;
    });
    
    if (found != types.cend()) {
        return *found;
    } else {
        return nullptr;
    }
}

GoodType* GoodsManager::getGoodType(const std::string& name) const {
    auto found = std::find_if(types.cbegin(), types.cend(), [&name](const GoodType* type){
        return name == type->getName();
    });

    if (found != types.cend()) {
        return *found;
    } else {
        return nullptr;
    }
}

GoodsManager::~GoodsManager() {
    for (GoodType* typeP: types) {
        delete typeP;
    }

    for (auto& factory: factories) {
        delete factory.second;
    }
}