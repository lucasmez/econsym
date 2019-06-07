#ifndef _GOODS_MANAGER_H_
#define _GOODS_MANAGER_H_

#include <set>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <Good/Factory/IGoodFactory.h>
#include <Good/Factory/IProducingFactory.h>
#include <Good/Type/IGoodType.h>
#include <Good/Common.h>

class GoodsManager {
    private:
        std::set<IGoodType*> types;
        std::map<std::string, IGoodFactory*> factories;

    public:
        GoodsManager() = default;

        /**
         * @brief  Get a good type that had been previously created, by goodtype id.
         * @retval pointer to good type.
         */
        IGoodType* getGoodType(good_id id) const;

        /**
         * @brief  Get a good type that had been previously created, by goodtype name.
         * @retval pointer to good type.
         */
        IGoodType* getGoodType(const std::string& name) const;

        /**
         * @brief  Adds a new good type to the goodsmanager register. Checks whether names
         * are repeated. If at least one good type cannot be added, none will.
         * @param  newTypes: collection of new good types to add. 
         * @retval true if all goods were added. False if none were added.
         */
        bool addGoodTypes(const std::set<IGoodType*>& newTypes) {
            // Check whether names are already taken.
            std::set<std::string> takenNames {};

            std::transform(
                types.cbegin(),
                types.cend(),
                std::inserter(takenNames, takenNames.begin()),
                [](const IGoodType* type){ 
                    return type->getName();
                }
            );

            for (const IGoodType* newType: newTypes) {
                const auto found = std::find(takenNames.cbegin(), takenNames.cend(), newType->getName());
                // Name is taken
                if (found != takenNames.cend()) {
                    return false;
                }
            }

            types.insert(newTypes.begin(), newTypes.end());
            return true;
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
                std::cerr << "Implement this..." << std::endl;
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
                std::cerr << "Implement this..." << std::endl;
                //TODO returns error saying regisredter factory is not of tyoe IProducingFactory
            }

            return factory->produce(std::forward<Args>(args)...); 
        }

        virtual ~GoodsManager();
};

#endif