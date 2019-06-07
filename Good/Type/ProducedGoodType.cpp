#include "./ProducedGoodType.h"

const std::string ProducedGoodType::typeName = "producedgoodtype";

ProducedGoodType::ProducedGoodType(std::string name, const GoodRecipe& recipe, producing_time time)
    : IProducedGoodType{name}, recipe{recipe}, producingTime{time} {}

ProducedGoodType::ProducedGoodType(std::string name, const GoodRecipe& recipe)
    : ProducedGoodType{name, recipe, 0} {}

ProducedGoodType::ProducedGoodType(std::string name)
    : ProducedGoodType{name, {}, 0 } {}

const GoodRecipe ProducedGoodType::getRecipe() const {
    return recipe;
}

void ProducedGoodType::setRecipe(const GoodRecipe& recipe) {
    if (recipe.contains(this, 1)) {
        std::cerr << "Implement this..." << std::endl;
        //TODO Return error code
    }
    this->recipe = recipe;
}

void ProducedGoodType::setRecipe(const Ingredients& ingredients) {
    GoodRecipe recipe {ingredients};
    setRecipe(recipe);
}

std::string ProducedGoodType::str() const {
    return this->IGoodType::str() + "\trecipe: [" + recipe.str() + "]";
}