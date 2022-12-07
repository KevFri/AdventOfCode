FLAGS=-Wall -Wpedantic -Wconversion -Wcast-align -Wunused -Wshadow -Wold-style-cast -Ofast #-Werror

all: template day01 day02 day03 day03_2 day04 day04_2 day05 day05_2 day06 day06_2
	
template:
	g++ -std=c++20 src/template.cpp -o bin/template.out -lfmt ${FLAGS}
	./bin/template.out

day01:
	g++ -std=c++20 src/AoC_01.cpp -o bin/AoC_01.out -lfmt ${FLAGS}
	./bin/AoC_01.out

day02:
	g++ -std=c++20 src/AoC_02.cpp -o bin/AoC_02.out -lfmt ${FLAGS}
	./bin/AoC_02.out

day03:
	g++ -std=c++20 src/AoC_03.cpp -o bin/AoC_03.out -lfmt ${FLAGS}
	./bin/AoC_03.out
	
day03_2:
	g++ -std=c++20 src/AoC_03_2.cpp -o bin/AoC_03_2.out -lfmt ${FLAGS}
	./bin/AoC_03_2.out

day04:
	g++ -std=c++20 src/AoC_04.cpp -o bin/AoC_04.out -lfmt ${FLAGS}
	./bin/AoC_04.out

day04_2:
	g++ -std=c++20 src/AoC_04_2.cpp -o bin/AoC_04_2.out -lfmt ${FLAGS}
	./bin/AoC_04_2.out

day05:
	g++ -std=c++20 src/AoC_05.cpp -o bin/AoC_05.out -lfmt ${FLAGS}
	./bin/AoC_05.out

day05_2:
	g++ -std=c++20 src/AoC_05_2.cpp -o bin/AoC_05_2.out -lfmt ${FLAGS}
	./bin/AoC_05_2.out

day06:
	g++ -std=c++20 src/AoC_06.cpp -o bin/AoC_06.out -lfmt ${FLAGS}
	./bin/AoC_06.out

day06_2:
	g++ -std=c++20 src/AoC_06_2.cpp -o bin/AoC_06_2.out -lfmt ${FLAGS}
	./bin/AoC_06_2.out

day07:
	g++ -std=c++20 src/AoC_07.cpp -o bin/AoC_07.out -lfmt ${FLAGS}
	./bin/AoC_07.out

clean:
	rm bin/*