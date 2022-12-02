all: template day01 
	
template:
	g++ -std=c++20 src/template.cpp -o bin/template.out -lfmt
	./bin/template.out

day01:
	g++ -std=c++20 src/AoC_01.cpp -o bin/AoC_01.out -lfmt
	./bin/AoC_01.out

clean:
	rm bin/*