#include "./GoodsHoldings.h"

void GoodsHoldings::add(const GoodType* goodType, num_goods quantity) {
    auto found = holdings.find(goodType);

    // GoodType not present in collection. Add it to collection.
    if (found == holdings.end()) {
        holdings.insert({goodType, quantity});

    // GoodType already present in collection: increase quantity.
    } else {
        found->second += quantity;
    }
}

num_goods GoodsHoldings::count(const GoodType* goodType) const {
    auto found = holdings.find(goodType);
    return found == holdings.end() ? 0 : found->second;
}

bool GoodsHoldings::remove(const GoodType* goodType, num_goods quantity) {
    auto found = holdings.find(goodType);
    
    if (found == holdings.end() || found->second < quantity) {
        return false;
    } else {
        found->second = found->second - quantity;
        return true;
    }
}

bool GoodsHoldings::transfer(const GoodType* goodType, num_goods quantity, IGoodsCollectionMutable& destination) {
    try {
        GoodsHoldings& convertedDest = dynamic_cast<GoodsHoldings&>(destination);

        if (this->remove(goodType, quantity)) {
            convertedDest.add(goodType, quantity);
        } else {
            return false;
        }

    } catch(std::bad_cast error) {
        //TODO: return error code
        return false;
    }

    return true;
}

bool GoodsHoldings::contains(const GoodType* goodType, num_goods quantity) const {
    return count(goodType) >= quantity;
}

bool GoodsHoldings::containedIn(const IGoodsCollection& col) const {
    bool contains {true};
    for (const auto& item: holdings) {
        if(!col.contains(item.first, item.second)) {
            contains = false;
        }
    }

    return contains;
}

std::string GoodsHoldings::str() const {
    std::string result {""};

    for (const auto& item: holdings) {
        result += "\n" + item.first->str() + "\tquantity: " + std::to_string(item.second);
    }

    return result;
}