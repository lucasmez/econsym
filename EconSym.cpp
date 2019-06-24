#include <iostream>
#include <Good/GoodsManager.h>
#include <Good/Type/NatureGoodType.h>
#include <Good/Type/ProducedGoodType.h>
#include <Good/Factory/NatureGoodFactory.h>
#include <Good/Factory/ProducedGoodFactory.h>
#include <Good/Collection/GoodsHoldings.h>

using namespace std;

int main() {
    GoodsManager gm {};
    // ActorsManager actorsManager {};

    // generator.generateTypes<ConsumerGoodType>(100);
    // generator.generateTypes<ProducerGoodType>(100);
    // generator.generateTypes<NatureGoodType>(100);

    NatureGoodFactory* natureGoodFactory = new NatureGoodFactory();
    ProducedGoodFactory* producedGoodFactory = new ProducedGoodFactory();
    gm.registerFactory<NatureGoodType>(natureGoodFactory);
    gm.registerFactory<ProducedGoodType>(producedGoodFactory);
    gm.registerFactory<ProducedGoodType>(producedGoodFactory);

    NatureGoodType* wood = new NatureGoodType("wood");
    NatureGoodType* ore = new NatureGoodType("ore");
    ProducedGoodType* food = new ProducedGoodType("food", {
        {{ore, 3}}
    }, 3);

    gm.addGoodTypes({wood, ore, food});
    gm.addGoodTypes({wood});
    
    // NatureGoodType* wood = gm.createGoodType<NatureGoodType>("wood");
    // NatureGoodType* ore = gm.createGoodType<NatureGoodType>("ore");
    // ProducedGoodType* food = gm.createGoodType<ProducedGoodType>("food");
    // food->setRecipe({
    //    {ore, 3}
    // });

    ProducedGoodType* bread = new ProducedGoodType("bread", {{
        {ore, 23},
        {wood, 5}
    }}, 2);
    gm.addGoodTypes({bread});

    GoodsHoldings myGoods {};    
    gm.spawnGood<NatureGoodType>(ore, 50, myGoods);
    gm.spawnGood<NatureGoodType>(wood, 10, myGoods);
    cout << myGoods << endl;
    cout << "producing..." << endl;
    gm.produceGood<ProducedGoodType>(bread, myGoods);
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


    std:: cout << myGoods.count(ore) << endl;
    std::cout << myGoods << endl;

    // square1.populate(natureGoodFactory);
    // square2.populate(natureGoodFactory, 2);
    // natureGoodFactory.setType(ore);
    // square3.populate(natureGoodFactory, 2);

    // actorsManager.generateActors();

    // World myWorld = 
    // World::create()
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

    // IGoodType* bread = goodsManager.createGoodType<ConsumerGoodType>("bread", {
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