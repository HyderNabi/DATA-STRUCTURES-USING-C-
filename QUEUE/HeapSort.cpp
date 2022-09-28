#include<iostream>
#include<conio.h>
#define LEN 20
using namespace std;
class Heap
{
        int data[LEN];
        int size;
public:
        Heap()
        {
                size = 1;
        }
        void insertElement(int elem)
        {
                data[size] = elem;
                Heapify(size);
                size++;


        }
        void Heapify(int i)
        {
                int parent = i/2;
                if (parent == 0)
                {
                        return;
                }
                else
                {
                        if(data[parent]<data[i])
                        {
                                swap(&data[parent],&data[i]);
                        }
                        Heapify(parent);
                }
        }
        void sort()
        {
                int len = size-1;
                for(int i = len;i>=1;i--)
                {
                        swap(&data[1],&data[i]);
                        DeleteHeapify(1,i);

                }
        }
        void DeleteHeapify(int i,int len)
        {
                int left = 2 * i;
                int right = (2 * i)+1;

                int largest = i;

                if(data[left]>data[largest] && left<len)
                {
                        largest = left;
                }
                if(data[right]>data[largest] && right<len)
                   {
                           largest = right;
                   }
                   if(largest  != i)
                   {
                           swap(&data[i],&data[largest]);
                           DeleteHeapify(largest,len);
                   }


        }
        void swap(int *a,int *b)
        {
                int temp;
                temp = *a;
                *a = *b;
                *b = temp;
        }
        print()
        {
                for(int i=1;i<size;i++)
                {
                        cout<<data[i]<<"\t";
                }
                cout<<endl;
        }
};
int main()
{
        Heap heap;
        int elem;
        while (true)
        {
                        cout<<"Enter the element = ";
                        cin>>elem;
                        if(elem == -1)
                        {
                                break;
                        }
                        heap.insertElement(elem);
        }
        cout<<"The Heap"<<endl;
        heap.print();
        heap.sort();
        cout<<"Sorted Elements of the Heap"<<endl;
        heap.print();

        getche();
        return 0;
}
