CXX = g++
CXXFLAGS = -pedantic -std=c++11 -Wall -Wextra -I./include

.PHONY: all clean archive

all: bin  ./bin/shop ./bin/bonusQuestion

bin :
	mkdir ./bin/

./bin/shop: src/shop.cpp include/shop.h
	$(CXX) $^ -o $@ $(CXXFLAGS)

./bin/bonusQuestion: ./src/bonusQuestion.cpp
	$(CXX) $^ -o $@

clean:
	find . -type f -name '*.o' -exec rm {} +
	find . -type f -name '*\~' -exec rm {} +
	rmdir ./bin/

archive:
	make -i clean && tar -czvf ROUILLE_HUBERT_TP2_CPP.tar ./*
