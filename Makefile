EXE = a.out

all: a.out

a.out: main.cpp
	g++ -std=c++11 $^ -o $@

clean:
	rm -rf ${EXE}