#include<iostream>
#include<conio.h>
using namespace std;
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp; 
}
void heapify(int arr[],int i,int n)
{
    int left = 2*i+1;
    int right = 2*i+2;
    int largest = i;

    if(arr[left] > arr[largest] && left<n)
    {
        largest = left;
    }
    if(arr[right] > arr[largest] && right<n)
    {
        largest = right;
    }

    if(largest != i)
    {
        swap(&arr[i],&arr[largest]);
        heapify(arr,largest,i);
    }
}
void MaxHeap(int arr[], int n)
{
    for(int i = ((n-1)/2)-1; i>=0 ; i--)
    {
        heapify(arr,i,n);
    }
}
void print(int arr[], int n)
{
    for(int i = 0; i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }
}
int main()
{
    int arr[] = {8,6,3,10,5,4,9};
    int n = 7;
    cout<<"Array before sorting"<<endl;
    print(arr,n);
    MaxHeap(arr,n);
    cout<<endl;
    print(arr,n);
    getche();
    return 0;

}