all: template day01 day02
	
template:
	g++ -std=c++20 src/template.cpp -o bin/template.out -lfmt
	./bin/template.out

day01:
	g++ -std=c++20 src/AoC_01.cpp -o bin/AoC_01.out -lfmt
	./bin/AoC_01.out

day02:
	g++ -std=c++20 src/AoC_02.cpp -o bin/AoC_02.out -lfmt
	./bin/AoC_02.out

clean:
	rm bin/*