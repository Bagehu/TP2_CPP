CXX = g++
CXXFLAGS = -pedantic -std=c++11 -Wall -Wextra -I./include

.PHONY: all clean archive git

all: bin  ./bin/rational

bin :
	mkdir ./bin/

./bin/rational: src/rational.cpp include/rational.h
	$(CXX) $^ -o $@ $(CXXFLAGS)

clean:
	find . -type f -name '*.o' -exec rm {} +
	find . -type f -name '*\~' -exec rm {} +
	rmdir ./bin/

archive:
	make -i clean
	tar -czvf ROUILLE_HUBERT_TP2_CPP.tar ./*

git:
	make -i clean
	git add .
	git commit
	git push
