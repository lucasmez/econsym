#include "./GoodFactory.h"

GoodFactory::GoodFactory(): inPipeline {nullptr} {};

void GoodFactory::spawn(IGoodsCollectionMutable& destinationCol) const {
    spawn(1, destinationCol);
}

void GoodFactory::spawn(num_goods n, IGoodsCollectionMutable& destinationCol) const {
    if (!inPipeline) {
        //TODO: Return error code ("[GoodFactory]: No good in pipeline.");
    }

    spawn(inPipeline, n, destinationCol);
}

void GoodFactory::spawn(const GoodType* type, IGoodsCollectionMutable& destinationCol) const {
    destinationCol.add(type, 1);
}

void GoodFactory::spawn(const GoodType* type, num_goods n, IGoodsCollectionMutable& destinationCol) const {
    destinationCol.add(type, n);
}

bool GoodFactory::destroy(const GoodType* goodType, num_goods quantity, IGoodsCollectionMutable& col) const {
    return col.remove(goodType, quantity);
}

void GoodFactory::setType(const GoodType* type) {
    inPipeline = type;
}