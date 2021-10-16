build:
	g++ -std=c++17 hello.cpp

rm_and_build:
	rm 'a.out' ; g++ -std=c++17 hello.cpp

all: rm_and_build
	 ./a.out

test: build
	./a.out

clean:
	rm a.out
