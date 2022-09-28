//Author:- Hyder Nabi
//Roll no:- 05
//MCA Batch 2020
#include<iostream>
#include<conio>
void fun(int arr[])
{
	for(int i = 0; i<3;i++ )
   {
   	cout<<arr[i];
   }
}
int main()
{
	int arr[2][3] = {1,2,3,4,5,6};
   fun(arr[0]);
   getche();
	return 0;
}

