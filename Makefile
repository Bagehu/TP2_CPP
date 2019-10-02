CXX = g++
CXXFLAGS = -pedantic -std=c++11 -Wall -Wextra -I./include

.PHONY: all clean distclean archive git

all: bin  ./bin/rational

bin :
	mkdir ./bin/

./bin/rational: src/rational.cpp include/rational.h
	$(CXX) $^ -o $@ $(CXXFLAGS)

distclean :
	clean
	find . -type f -name '*\~' -exec rm {} +
	rm -f ./bin/*

clean:
	find . -type f -name '*.o' -exec rm {} +

archive:
	make -i distclean
	tar -czvf ROUILLE_HUBERT_TP2_CPP.tar ./*

git:
	make -i distclean
	git add .
	git commit
	git push
