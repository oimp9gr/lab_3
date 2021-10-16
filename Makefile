build:
	g++ -std=c++17 hello.cpp

a.out: hello.cpp
	build

test:
	./a.out "$(name)"

clear:
	rm a.out
