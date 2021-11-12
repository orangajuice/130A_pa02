#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class T>
class heap
{
	public:
		static const int SMALL = -999999;
		static const int MIG = 999999;
		heap() : {};
		heap(int length, bool min_or_not) {};
		void insert(T a);
		void remove(T a);
		void heapify(int i);
		T get_root();
		T extract_root();
		T get_min();
		T get_max();
		int get_size() {return size;}
		int search(T a);
		int left(int i){return 2*i + 1;}
		int right(int i){return 2*i + 2;}
		int parent(int i) {return (i-1)/2;}
	private:
		int size;
		bool is_min;
		std::vector<T> newheap;
};

template <class T>
void swap(T *x, T *y)
{
	T temp = *x;
	*x = *y;
	*y = temp;
}

#endif