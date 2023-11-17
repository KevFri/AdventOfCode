all: clean cmake build execute

clean:
	rm -rf build/*
	rm -rf bin/*

cmake:
	cmake -B build

.PHONY: build
build:
	cd ./build && make -j17

tpl:
	./bin/tpl

aoc01_1:
	./bin/aoc01_1

aoc01_2:
	./bin/aoc01_2

execute: tpl aoc01_1 aoc01_2

