#include "heap.h"

template <class T>
heap<T>::heap(int length, bool min_or_not)
{
    size = length;
    is_min = min_or_not;
}

template <class T>
void heap<T>::insert(T a)
{
    if(is_min == true)
    {
        size++;
        int i = size - 1;
        newheap.resize(size);

        newheap[i] = a;

        while(i!=0 && newheap[parent(i)]>newheap[i])
        {
            swap(&newheap[i],&newheap[parent(i)]);
            i = parent(i);
        }
    }
    else
    {
        size++;
        int i = size - 1;
        newheap.resize(size);

        newheap[i] = a;
        while(i != 0 && newheap[parent(i)]<newheap[i])
        {
            swap(&newheap[i], &newheap[parent(i)]);
            i = parent(i)
        }
    }
}

template <class T>
void heap<T>::remove(T a)
{
    if(is_min == true)
    {
        int i = search(a);
        newheap[i] = SMALL;
        while(i != 0 && newheap[parent(i)]>newheap[i])
        {
            swap(&newheap[i], &newheap[parent[i]]);
            i = parent(i);
        }
        extract_root();
    }
    else
    {
        int i = search(a);
        newheap[i] = BIG;
        WHILE(i != 0 && newheap[parent(i)]<newheap[i])
        {
            swap(&newheap[i], &newheap[parent(i)]);
            i = parent(i);
        }
        extract_root();
    }
}

template <class T>
void heap<T>::heapify(int i)
{
    if(is_min == true)
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

template <class T>
T heap<T>::get_root()
{
    return newheap[0];
}

template <class T>
T heap<T>::extract_root()
{
    int root = newheap[0];
    newheap[0] = newheap[size-1];
    size--;
    newheap.resize(size);
    heapify(0);
    return root;
}

template <class T>
T heap<T>::get_min()
{
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

template <class T>
T heap<T>::get_max()
{
    T max = newheap[0];
    for(unsigned int i=0;i<size;i++)
    {
        if(newheap[i] > max)
        {
            max = newheap[i]
        }
    }
    return max;
}

template <class T>
int heap<T>::search(T a)
{
    for(unsigned int i=0;i<size;i++)
    {
        if(newheap[i]==a)
        {
            return i;
        }
        if(newheap[i]!=a && i=size-1)
        {
            return -1;//not found
        }
    }
}