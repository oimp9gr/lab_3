build:
	g++ -std=c++17 hello.cpp

rm_and_build:
	rm 'a.out' ; g++ -std=c++17 hello.cpp

all: rm_and_build
	 ./a.out -d yes

test: build
	./a.out -d yes

clean:
	rm a.out
