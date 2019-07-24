#include <iostream>
#include <Good/GoodsManager.h>
#include <Good/Type/NatureGoodType.h>
#include <Good/Type/ProducedGoodType.h>
#include <Good/Factory/NatureGoodFactory.h>
#include <Good/Factory/ProducedGoodFactory.h>
#include <Good/Collection/GoodsHoldings.h>
#include <World/Map/Map.h>

using namespace std;

int main() {
    GoodsManager gm {};

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

    std:: cout << myGoods.count(ore) << endl;
    std::cout << myGoods << endl;

    Map myMap {10, 10};
    for (auto& v: myMap.grid) {
        cout << endl;
        for (auto& w: v) {
            cout << w.getLocation().getPosition().x << ",";
            cout << w.getLocation().getPosition().y << " ";
        }
    }

    auto iter = myMap.spiral_begin(4, 4);
    while (iter != myMap.spiral_end()) {
        cout << iter->getLocation().getPosition().x << ",";
        cout << iter->getLocation().getPosition().y << endl;
        iter++;
    }

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