all: project2

project2: main.cpp
	g++ -std=c++11 $^ -o $@

clean:
	rm -rf ${EXE}