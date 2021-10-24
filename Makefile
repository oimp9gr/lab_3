build:
	g++ -std=c++17 .tests/"$(name)".cpp -o "$(name)".out

test:
	./"$(name)".out -d yes "[task:$(name)]"

clear:
	rm [a-z][0-9].out
