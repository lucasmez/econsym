#include <cassert>
#include "./ProducedGoodFactory.h"
#include <Good/Type/IProducedGoodType.h>

bool ProducedGoodFactory::produce(IGoodsCollectionMutable& fromTo) const {
    return produce(fromTo, fromTo);
}

bool ProducedGoodFactory::produce(const IProducedGoodType* goodType, IGoodsCollectionMutable& fromTo) const {
    return produce(goodType, fromTo, fromTo);
}

bool ProducedGoodFactory::produce(IGoodsCollectionMutable& dest, IGoodsCollectionMutable& source) const {
    if (!inPipeline) {
        //TODO Return error code ("[GoodFactory]: No good in pipeline.");
    }

    const IProducedGoodType* producedGoodType = dynamic_cast<const IProducedGoodType*>(inPipeline);
    assert(producedGoodType);

    return produce(producedGoodType, dest, source);
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
    // this->spawn(dynamic_cast<const GoodType*>(goodType), dest);
    // TimerEmitter::in(goodType->productionTime, [this, goodType](){
        this->spawn(dynamic_cast<const GoodType*>(goodType), dest);
    // });

    return true;
}