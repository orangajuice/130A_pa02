// Author: Xianqi Wang, Guang Yang
#ifndef MM_H
#define MM_H

#include "heap.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class T>
class MM
{
	public:
		MM() // default constructor
		{
			heap<T> n1(0,true);
			heap<T> n2(0,false);
			min = n1;
			max = n2;
		}
		T getsize1() {return min.get_size();}
		T getsize2() {return max.get_size();}
		bool gettype() {return max.gettype();}

		void insert(T a)
		{
			if(min.get_size()==0 && max.get_size()==0)//speical case when two heaps are empty
			{
				maximum = a;
				minimum = a;
				median = a;
				max.insert(a);
			}
			else
			{
				if(a > median)
				{
					min.insert(a);
				}
				else
				{
					max.insert(a);
				}

				//check balance
				int def = min.get_size()-max.get_size();
				if(def == 2) //mean that min has too more
				{
					T newmax = min.extract_root();
					max.insert(newmax);
					median = max.get_root();
				}
				if(def == -2) //mean that max has too more
				{
					T newmin = max.extract_root();
					min.insert(newmin);
					median = max.get_root();
				}
				if(def == 1)
				{
					median = min.get_root();
				}
				if(def == -1)
				{
					median = max.get_root();
				}
				if(def == 0)
				{
					median = max.get_root();
				}
			}

			// redefine the maximum/minimum
			if(a > maximum){
				maximum = a;
			}else if(a < minimum){
				minimum = a;
			}

		}

		void remove(T a)
		{
			if(a > median)
			{
				min.remove(a);
			}
			else
			{
				max.remove(a);
			}

			// rebalance
			int def = min.get_size() - max.get_size();
			if(def == 2) //mean that min has too more
			{
				T newmax = min.extract_root();
				max.insert(newmax);
				median = max.get_root();
			}
			if(def == -2)
			{
				T newmin = max.extract_root();
				min.insert(newmin);
				median = max.get_root();
			}
			if(def==1)
			{
				median = min.get_root();
			}
			if(def == -1 || def == 0)
			{
				median = max.get_root();
			}

			// refresh minimum and maximum by linear searching
			minimum = max.get_min();
			maximum = min.get_max();
		}

		T get_median() {return median;}
		T get_minimum() {return minimum;}
		T get_maximum() {return maximum;}
		int get_size(){return max.get_size()+min.get_size();}
		
		int search(T a)
		{ // a linear search
			if(a > median)
			{
				return min.search(a);
			}
			else
			{
				return max.search(a);
			}
		}
	private:
		// three variables to track the minimum, maximum and median
        T minimum;
        T maximum;
        T median;
		
		// a minHeap and a maxHeap
		heap<T> min;
		heap<T> max;
};

#endif