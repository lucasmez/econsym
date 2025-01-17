#=======================================
# VARIABLES
#=======================================

# Compiler Variables
CXX = g++
CXXFLAGS = -Wall -g --std=c++14 -I ./
VPATH=Good:Good/Factory:Good/Type:Good/Collection:Common:Object:Object/Location:World

# Dependency Graph Variables
CIRCLE2DOT_PATH =../tools/circle2dot/circletodot.pl
DEP_GRAPH_FILENAME =dependency_tree.png

#=======================================
# MAIN TASK
#=======================================
OBJ_FILES = EconSym.o \
GoodsManager.o \
GoodsHoldings.o \
GoodRecipe.o \
IGoodFactory.o \
ProducedGoodFactory.o \
IGoodType.o \
ProducedGoodType.o \
Object.o \
Location2D.o \
World.o \
WorldBuilder.o \


EconSym: $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o EconSym $(OBJ_FILES)


#=======================================
# OBJECT FILES
#=======================================

EconSym.o: Good/GoodsManager.h \
Good/Type/NatureGoodType.h \
Good/Factory/IGoodFactory.h \
Good/Factory/NatureGoodFactory.h \
Good/Collection/IGoodsCollection.h \
Good/Type/IGoodType.h \
Good/Common.h

GoodsManager.o: Good/Factory/IGoodFactory.cpp \
Good/Type/IGoodType.h \
Good/Common.h

GoodsHoldings.o: Good/Collection/GoodsHoldings.cpp \
Good/Collection/GoodsHoldings.h \
Good/Collection/IGoodsCollection.h \
Good/Type/IGoodType.h \
Good/Common.h

GoodRecipe.o: Good/Collection/GoodRecipe.cpp \
Good/Collection/GoodRecipe.h \
Good/Collection/IGoodsCollection.h \
Good/Type/IGoodType.h \
Good/Common.h

IGoodFactory.o: Good/Factory/IGoodFactory.cpp \
Good/Factory/IGoodFactory.h \
Good/Collection/IGoodsCollection.h \
Good/Type/IGoodType.h \
Good/Common.h

ProducedGoodFactory.o: Good/Factory/ProducedGoodFactory.cpp \
Good/Factory/ProducedGoodFactory.h \
Good/Factory/IGoodFactory.h \
Good/Factory/IProducingFactory.h \
Good/Collection/IGoodsCollection.h \
Good/Type/IGoodType.h \
Good/Type/IProducedGoodType.h \
Good/Common.h

IGoodType.o: Good/Type/IGoodType.cpp \
Good/Type/IGoodType.h \
Good/Common.h

ProducedGoodType.o: Good/Type/ProducedGoodType.cpp \
Good/Type/ProducedGoodType.h \
Good/Type/IProducedGoodType.h \
Good/Collection/GoodRecipe.h \
Good/Collection/IGoodsCollection.h \
Good/Type/IGoodType.h \
Good/Common.h

Object.o: Object/Object.cpp \
Object/Object.h

Location2D.o: Object/Location/Location2D.cpp \
Object/Location/Location2D.h

World.o: World/World.cpp \
World/World.h

WorldBuilder.o: World/WorldBuilder.cpp \
World/WorldBuilder.h

#=======================================
# MISC. COMMANDS
#=======================================

clean:
	rm *.o \
	rm $(DEP_GRAPH_FILENAME);

dependency-graph:
	rm ./$(DEP_GRAPH_FILENAME); \
	$(CIRCLE2DOT_PATH) --paths --include . > EconSym.cpp.dot && \
	 dot -Tpng EconSym.cpp.dot > $(DEP_GRAPH_FILENAME) && rm EconSym.cpp.dot;