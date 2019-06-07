#include "./IGoodFactory.h"

IGoodFactory::~IGoodFactory() {}

void IGoodFactory::spawn(const IGoodType* type, IGoodsCollectionMutable& destinationCol) const {
    destinationCol.add(type, 1);
}

void IGoodFactory::spawn(const IGoodType* type, num_goods n, IGoodsCollectionMutable& destinationCol) const {
    destinationCol.add(type, n);
}

bool IGoodFactory::destroy(const IGoodType* goodType, num_goods quantity, IGoodsCollectionMutable& col) const {
    return col.remove(goodType, quantity);
}
