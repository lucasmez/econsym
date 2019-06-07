#include <iostream>
#include <Good/GoodsManager.h>
#include <Good/Type/NatureGoodType.h>
#include <Good/Type/ProducedGoodType.h>
#include <Good/Factory/NatureGoodFactory.h>
#include <Good/Factory/ProducedGoodFactory.h>
#include <Good/Collection/GoodsHoldings.h>

using namespace std;

int main() {
    GoodsManager goodsManager {};
    // ActorsManager actorsManager {};

    // goodsManager.generateTypes<ConsumerGoodType>(100);
    // goodsManager.generateTypes<ProducerGoodType>(100);
    // goodsManager.generateTypes<NatureGoodType>(100);

    NatureGoodType* wood = goodsManager.createGoodType<NatureGoodType>("wood");
    NatureGoodType* ore = goodsManager.createGoodType<NatureGoodType>("ore");

    NatureGoodFactory natureGoodFactory = goodsManager.createGoodFactory<NatureGoodFactory>();

    GoodsHoldings myCollection;
    natureGoodFactory.spawn(ore, 20, myCollection);
    natureGoodFactory.spawn(wood, 10, myCollection);
    num_goods woodQty = myCollection.count(wood);
    std::cout << woodQty << endl;

    //===PRODUCING
    ProducedGoodType* food = goodsManager.createGoodType<ProducedGoodType>("food");
    food->setRecipe({
       {ore, 3}
    });

    ProducedGoodType* bread = goodsManager.createGoodType<ProducedGoodType>("bread");
    bread->setRecipe({
        {ore, 23},
        {wood, 5}
    });

    ProducedGoodFactory producingPipeline = goodsManager.createGoodFactory<ProducedGoodFactory>(food);
    producingPipeline.produce(myCollection);

    producingPipeline = goodsManager.createGoodFactory<ProducedGoodFactory>(bread->getId());
    producingPipeline.produce(myCollection);

        //NEW WAY================================
        // setup goodsmanager
        // gm.registerFactory<NatureGoodType>(natureGoodFactory);
        // gm.registerFactory<ProducedGoodType>(producedGoodFactory);
        // gm.registerFactory<QuicklyProducedType>(quicklyProducedFactory);
        
        // gm.spawnGood<NatureGoodType>(ore, destCollection)
        // gm.produceGood<ProducedGoodType>(bread, collection, inProductionColl);

        // // setup actorsmanager
        // IProducingFactory* producingFactory = gm.getFactory<QuicklyProducedType>();
        // am.setFactory(producingFactory);
        // // in actor object
        // factory->produce(bread, myGoods, myProductionPipeline);
        
        // // in goodsmanager
        // template <Type T>
        // void spawnGood(Type* type, Coll coll) {
        //     GoodFactory* factory = getFactory<T>();
        //     factory->spawn(type, coll);
        // }

        // template <Type>
        // void produceGood(Type* type, Coll& coll, Coll& inProd) {
        //     IProducingFactory* factory = getFactory(Type::name);
        //     factory->produce(type, coll, inProd);
        // }
        //END NEW WAY============================


    std::cout << myCollection << endl;

    // square1.populate(natureGoodFactory);
    // square2.populate(natureGoodFactory, 2);
    // natureGoodFactory.setType(ore);
    // square3.populate(natureGoodFactory, 2);

    // actorsManager.generateActors();

    // World myWorld = 
    // myWorld
    //     .builder()
    //     .settings(worldSettings)
    //     .setGoodsManager(goodsManager)
    //     .setActorsManager(actorsManager)
    //     .fromMap(mapBinaryFile)
    //     .build();

    // World world = World::create()
    //     .goods(goodsManager)
    //         .fromSettings(goodsSettings)
    //         .createTypes()
    //     .actors(actorsManager)
    //         .fromFile(actorsFile)
    //     .map()
    //         .fromFile(mapFile)
        


    // while(true) {
    //     world.turn();
    // }

    // GoodType* bread = goodsManager.createGoodType<ConsumerGoodType>("bread", {
    //     { ConsumerGoodType::attributes::longevity, 10 },
    //     { ConsumerGoodType::attributes::weight, 10 }
    //  });

    

    // GoodFactory goodFactory = goodsManager.createGoodFactory<NatureGoodFactory>;
    // GoodFactory natureGoodFactory = goodsManager.createGoodFactory<NatureGoodType>();
    // Good wood1 = natureGoodFactory.spawn(wood);
    // Good wood2 = natureGoodFactory.spawn(wood);
    // Good wood3 = natureGoodFactory.spawn(wood);
    // GoodFactory toolFactory = goodsManager.createGoodFactory(wood);
    // Good tool1 = toolFactory.spawn();

    // GoodFactory woodFactory = goodsManager.createGoodFactory<NatureGoodType>(wood);
    // GoodFactory breadFactory = goodsManager.createGoodFactory<ConsumerGoodType>(bread);
    // square1.populate(woodFactory, 10);
    // actor1.produce(breadFactory, 1);
    //     breadFactory.produce({actorLabor1, actorIngredient2});

}