#ifndef _GOOD_RECIPE_H
#define _GOOD_RECIPE_H

#include <map>
#include <Good/Common.h>
#include <Good/Type/IGoodType.h>
#include <Good/Collection/IGoodsCollection.h>

typedef std::map<const IGoodType*, num_goods> Ingredients;

class GoodRecipe: public IGoodsCollection {
    private:
        Ingredients ingredients;

    public:
        GoodRecipe();
        GoodRecipe(const Ingredients& ingredients);
        virtual ~GoodRecipe() = default;

        const Ingredients& getIngredients() const;
        virtual num_goods count(const IGoodType*) const override;
        virtual bool contains(const IGoodType*, num_goods) const override;
        virtual bool containedIn(const IGoodsCollection&) const override;
        virtual std::string str() const override;
};


#endif