// Author: Xianqi Wang, Guang Yang
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
		heap() : size(0) {} // default constructor
		heap(int length, bool min_or_not)
		{
			size = length;
			is_min = min_or_not;
		}
		
		bool gettype() {return is_min;}

		void insert(T a)
		{
			// first insert it at the end of heap
			size++;
			int i = size - 1;
			newheap.resize(size);
			newheap[i] = a;

			if(is_min == true)// if minHeap
			{
				while(i!=0 && newheap[parent(i)]>newheap[i])//bubble up when the current node is smaller than its parent
				{
					swap(&newheap[i],&newheap[parent(i)]);
					i = parent(i);
				}
			}
			else// if maxHeap
			{
				while(i != 0 && newheap[parent(i)]<newheap[i])
				{ // bubble up if the current node is greater than its parent
					swap(&newheap[i], &newheap[parent(i)]);
					i = parent(i);
				}
			}
		}

		void remove(T a){
			int i = search(a); // find the position
			while(i != 0){ // bubble the node to the root
				swap(&newheap[i], &newheap[parent(i)]);
				i = parent(i);
			}
			extract_root(); // delete the root
		}

		void heapify(int i) // heapify the subtree at index i
		{
			if(is_min)
			{
				int l = left(i);
				int r = right(i);
				int smallest = i;
				if(l < size && newheap[l] < newheap[i])
				{
					smallest = l;
				}
				if(r < size && newheap[r] < newheap[smallest])
				{
					smallest = r;
				}
				if(smallest != i)
				{
					swap(&newheap[i], &newheap[smallest]);
					heapify(smallest);
				}
			}
			else
			{
				int l = left(i);
				int r = right(i);
				int biggest = i;
				if(l < size && newheap[l] > newheap[i])
				{
					biggest = l;
				}
				if(r < size && newheap[r] > newheap[biggest])
				{
					biggest = r;
				}
				if(biggest != i)
				{
					swap(&newheap[i], &newheap[biggest]);
					heapify(biggest);
				}
			}
		}
		T get_root() {return newheap[0];}
		T extract_root()
		{
			T root = newheap[0];
			newheap[0] = newheap[size-1]; // put the last node to the root
			size--;
			newheap.resize(size);
			heapify(0); // and start heapify
			return root;
		}	
		T get_min()
		{ // linear search for a min: O(n)
			T min = newheap[0];
			for(unsigned int i=0;i<size;i++)
			{
				if(newheap[i] < min)
				{
					min = newheap[i];
				}
			}
			return min;
		}
		T get_max()
		{ // linear search for a max: O(n)
			T max = newheap[0];
			for(unsigned int i=0;i<size;i++)
			{
				if(newheap[i] > max)
				{
					max = newheap[i];
				}
			}
			return max;
		}

		int get_size() {return size;}

		int search(T a)
		{// linear search
			for(unsigned int i=0;i<size;i++)
			{
				if(newheap[i]==a)
				{
					return i;
				}
				if(newheap[i]!=a && i==size-1)
				{
					return -1;//not found
				}
			}
			return -1;
		}

		// return the indeces of relevant nodes.
		int left(int i){return 2*i + 1;}
		int right(int i){return 2*i + 2;}
		int parent(int i) {return (i-1)/2;}
		
		void swap(T *x, T *y) // swap two heap elements
		{
			T temp = *x;
			*x = *y;
			*y = temp;
		}
	private:
		int size; // the size of this heap
		bool is_min; // true if minHeap; false if maxHeap.
		std::vector<T> newheap; // the container for heap
};


#endif