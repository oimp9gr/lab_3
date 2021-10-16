build:
	g++ -std=c++17 hello.cpp

a.out:
	./a.out

rm_and_build:
	rm 'a.out' ; g++ -std=c++17 hello.cpp

all: rm_and_build
	 ./a.out

test:
	./a.out "$(name)"

clean:
	rm a.out
