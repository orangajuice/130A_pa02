#include "MM.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    string heaptype = argv[1];
    string insertword;
    string removeword;
    ifstream insertfile(argv[2]);
    ifstream removefile(argv[3]);

    if(heaptype == "heap")
    {
        int size = 0;
        // std::vector<int> heap_array;
        heap<int> mi(0, true);
        heap<int> mx(0, false);
        while(getline(insertfile,insertword))
        {
            size += 1;
            mx.insert(stoi(insertword));
            mi.insert(stoi(insertword));
        }
        insertfile.close();
        while(getline(removefile,removeword))
        {
            size -= 1;
            mx.remove(stoi(removeword));
            mi.remove(stoi(removeword));
        }
        removefile.close();

        cout << "Min Heap:" << endl;
        cout << "Size = " << mi.get_size() << endl;
        cout << "Min = " << mi.get_min() << endl;
        cout << "Max = " << mi.get_max() << endl;
        cout << "Max Heap:" << endl;
        cout << "Size = " << mx.get_size() << endl;
        cout << "Min = " << mx.get_min() << endl;
        cout << "Max = " << mx.get_max() << endl;
    }
    else if(heaptype == "minmedianmax")
    {
        int size = 0;
        std::vector<int> heap_array;
        // heap<int> n1(0,true), n2(0,false);
        MM<int> MMHeap(0,0);
        while(getline(insertfile,insertword))
        {
            size += 1;
            MMHeap.insert(stoi(insertword));
        }
        insertfile.close();
        while(getline(removefile,removeword))
        {
            size -= 1;
            MMHeap.remove(stoi(removeword));
        }
        removefile.close();

        cout << "MinMedianMaxSketch:" << endl;
        cout << "Size = " << MMHeap.get_size() << endl;
        cout << "Min = " << MMHeap.get_minimum() << endl;
        cout << "Max = " << MMHeap.get_maximum() << endl;
    }
    return 0;
}