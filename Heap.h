#ifndef HEAP_H
#define HEAP_H
#include <bits/stdc++.h>
#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

template <typename T>
class Heap{
	public:
		Heap(bool (*comp)(T,T));
		void insert(T a);
		void remove(T a);
		T get_root();
		T extract_root();
		T get_min();
		T get_max();
		int get_size(){return size;}
		bool search(T a);
		int height();
		int leftIndex(int i){return 2*i + 1;}
		int rightIndex(int i){return 2*i + 2;}


	private:
		vector<T> min;
		bool (*comp)(T,T);
		
		int size;
};


	
#endif
