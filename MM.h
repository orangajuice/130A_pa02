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
		MM(int a, int b)
		{
			size1 = a;
			size2 = b;
			heap<T> n1(0,true);
			heap<T> n2(0,false);
			min = n1;
			max = n2;
		}
		void insert(T a)
		{
			if(size1==0&&size2==0)//speical case when two heaps are empty
			{
				maximum = a;
				minimum = a;
				median = a;
				max.insert(a);
				size2++;
			}
			else
			{
				if(a > median)
				{
					min.insert(a);
					size1++;
				}
				else
				{
					max.insert(a);
					size2++;
				}
				//check balance
				int def = size1 - size2;
				if(def==2||def==-2) //rebalance
				{
					if(def > 1) //mean that min has too more
					{
						T newmax = min.extract_root();
						max.insert(newmax);
						median = max.get_root();
					}
					else if(def < 1) //mean that max has too more
					{
						T newmin = max.extract_root();
						min.insert(newmin);
						median = max.get_root();
					}
				}
				else if(def==1)
				{
					median = min.get_root();
					//check min
					minimum = max.get_min();
					//check max
					maximum = min.get_max();
				}
				else if(def == -1)
				{
					median = max.get_root();
					//check min
					minimum = max.get_min();
					//check max
					maximum = min.get_max();
				}
			}
		}

		void remove(T a)
		{
			if(a > median)
			{
				min.remove(a);
				size1--;
			}
			else
			{
				max.remove(a);
				size2--;
			}
			int def = size1 - size2;
			if(def==2 || def==-2)
			{
				if(def > 1) //mean that min has too more
				{
					T newmax = min.extract_root();
					max.insert(newmax);
					median = max.get_root();
				}
				else if(def < -1)
				{
					T newmin = max.extract_root();
					min.insert(newmin);
					median = max.get_root();
				}
			}
			else if(def==1)
			{
				median = min.get_root();
				//check min
				minimum = max.get_min();
				//check max
				maximum = min.get_max();
			}
			else if(def == -1)
			{
				median = max.get_root();
				//check min
				minimum = max.get_min();
				//check max
				maximum = min.get_max();
			}
		}

		T get_median() {return median;}
		T get_minimum() {return minimum;}
		T get_maximum() {return maximum;}
		int get_size(){return size1+size2;}
		bool search(T a)
		{
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
		int size1; //size of min
        int size2; //size of max
        T minimum;
        T maximum;
        T median;
		heap<T> min;
		heap<T> max;
};

#endif