#ifndef _GOODS_MANAGER_H_
#define _GOODS_MANAGER_H_

#include <vector>
#include <map>
#include <utility>
#include <Good/Factory/IGoodFactory.h>
#include <Good/Factory/IProducingFactory.h>
#include <Good/Type/GoodType.h>
#include <Good/Common.h>

class GoodsManager {
    private:
        std::vector<GoodType*> types;
        std::map<std::string, IGoodFactory*> factories;

    public:
        GoodsManager() = default;

        /**
         * @brief  Get a good type that had been previously created, by goodtype id.
         * @retval pointer to good type.
         */
        GoodType* getGoodType(good_id id) const;

        /**
         * @brief  Get a good type that had been previously created, by goodtype name.
         * @retval pointer to good type.
         */
        GoodType* getGoodType(const std::string& name) const;

        /**
         * @brief  Creates a new good type with given name and push it to "types" list.
         * @param  name: name of good type.
         * @retval pointer to created good type.
         */
        template <typename GType>
        GType* createGoodType(std::string name) {
            GType* newType = new GType {name};
            types.push_back(newType);
            return newType;
        }

        /**
         * @brief  Registers a factory for the specified good type.
         * @param  factory: factory to register
         * @retval None
         */
        template <typename GType>
        void registerFactory(IGoodFactory* factory) {
            auto result = factories.insert({ GType::typeName, factory });
            if (result.second == false) {
                //TODO return error code for facotry with given name already registered
            }
        }

        /**
         * @brief  Get a factory that had been previously registered for the specified good type.
         * @retval pointer to factory.
         */
        template <typename GType>
        IGoodFactory* getFactory() {
            return factories[GType::typeName];
        }

        /**
         * @brief  Finds factory for type and spawns a new good of the specified good type.
         * @note:  Makes use of c++ perfect forwarding to call good factory
         * @param  args: To know the list of arguments, check the spawn method documentation
         * for the registered factory.
         * @retval None
         */
        template <typename GType, typename... Args>
        void spawnGood(Args&&... args) {
            IGoodFactory* factory = getFactory<GType>();
            return factory->spawn(std::forward<Args>(args)...);
        }

        /**
         * @brief  Finds factory for type and produces a new good of the specified good type.
         * @note:  Makes use of c++ perfect forwarding to call good factory
         * @param  args: To know the list of arguments, check the spawn method documentation
         * for the registered factory.
         * @retval None
         */
        template <typename GType, typename... Args>
        bool produceGood(Args&&... args) {
            IProducingFactory* factory = dynamic_cast<IProducingFactory*>(getFactory<GType>());

            if (!factory) {
                //TODO returns error saying regisredter factory is not of tyoe IProducingFactory
            }

            return factory->produce(std::forward<Args>(args)...); 
        }

        virtual ~GoodsManager();
};

#endif