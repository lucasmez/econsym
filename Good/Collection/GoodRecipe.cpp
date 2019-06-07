#include "./GoodRecipe.h"

GoodRecipe::GoodRecipe() {};
GoodRecipe::GoodRecipe(const Ingredients& ingredients): ingredients{ingredients} {}

const Ingredients& GoodRecipe::getIngredients() const {
    return ingredients;
}

num_goods GoodRecipe::count(const GoodType* goodType) const {
    auto found = ingredients.find(goodType);
    return found == ingredients.end() ? 0 : found->second;
}

std::string GoodRecipe::str() const {
    std::string result {""};

    for (const auto& item: ingredients) {
        result += std::to_string(item.second) + "-" + item.first->getName() + ",";
    }

    return result;
}

bool GoodRecipe::contains(const GoodType* goodType, num_goods quantity) const {
    return count(goodType) >= quantity;
}

bool GoodRecipe::containedIn(const IGoodsCollection& col) const {
    bool contains {true};
    for (const auto& item: ingredients) {
        if(!col.contains(item.first, item.second)) {
            contains = false;
        }
    }

    return contains;
}
