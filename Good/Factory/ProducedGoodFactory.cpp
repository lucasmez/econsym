#include <cassert>
#include "./ProducedGoodFactory.h"
#include <Good/Type/IProducedGoodType.h>
#include <Common/Emitter/TimeEmitter.h>

bool ProducedGoodFactory::produce(const IProducedGoodType* goodType, IGoodsCollectionMutable& fromTo) const {
    return produce(goodType, fromTo, fromTo);
}

bool ProducedGoodFactory::produce(const IProducedGoodType* goodType, IGoodsCollectionMutable& dest, IGoodsCollectionMutable& source) const {
    const GoodRecipe& recipe = goodType->getRecipe();

    // Check whether the source goods collection has the necessary ingredients for the production
    if (!recipe.containedIn(source)) {
        return false;
    }

    // Remove all necessary ingredients for production from the source good collection
    for (const auto& ingredient: recipe.getIngredients()) {
        this->destroy(ingredient.first, ingredient.second, source);
    }

    // Generate the produced good and add it to the destination goods collection
    // this->spawn(dynamic_cast<const IGoodType*>(goodType), dest);
    // TimeEmitter::in(goodType->productionTime, [this, goodType, dest](){
        this->spawn(goodType, dest);
    // });

    return true;
}