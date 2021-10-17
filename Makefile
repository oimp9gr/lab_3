build:
	g++ -std=c++17 run_tests.cpp

a.out: run_tests.cpp
	build

test:
	./a.out -d yes "$(name)"

clear:
	rm a.out
