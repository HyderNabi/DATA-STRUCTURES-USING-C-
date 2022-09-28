#include <iostream.h>
#include <conio.h>
 

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 

int partition(int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l - 1);
 
    for (int j = l; j <= h - 1; j++) {
        if (arr[j] <= x) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}
 

void QuickSort(int arr[], int l, int h)
{
    
    int stack[8];
 
    // initialize top of stack
    int top = -1;
 
    
    stack[++top] = l;
    stack[++top] = h;
 

    while (top >= 0) {
        
        h = stack[top--];
        l = stack[top--];
 
        
        int p = partition(arr, l, h);
 
        
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
 
        
        if (p + 1 < h) {
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}
 

void print(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        cout << arr[i] << " ";
}
 

int main()
{
    int arr[] = { 9,1,6,3,9,4,2,6};
    int n = 8;
    QuickSort(arr, 0, n - 1);
    print(arr, n);
    getche();
    return 0;
}
 