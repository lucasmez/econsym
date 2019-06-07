#include "./GoodsManager.h"

IGoodType* GoodsManager::getGoodType(good_id id) const {
    auto found = std::find_if(types.cbegin(), types.cend(), [&id](const IGoodType* type){
        return type->getId() == id;
    });
    
    if (found != types.cend()) {
        return *found;
    } else {
        return nullptr;
    }
}

IGoodType* GoodsManager::getGoodType(const std::string& name) const {
    auto found = std::find_if(types.cbegin(), types.cend(), [&name](const IGoodType* type){
        return name == type->getName();
    });

    if (found != types.cend()) {
        return *found;
    } else {
        return nullptr;
    }
}

GoodsManager::~GoodsManager() {
    for (IGoodType* typeP: types) {
        delete typeP;
    }

    for (auto& factory: factories) {
        delete factory.second;
    }
}