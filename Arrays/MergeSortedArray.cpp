#include<iostream>
#include<conio>
#define len 50
class mergeArray{
	int arr1[len],arr2[len],arr3[len],size1,size2,size;
   public:

void readArray1()
{
  cout<<"Enter size of an Array1"<<endl;
  cin>>size1;
  cout<<"Enter the sorted "<<size1<<" elements of an array1"<<endl;
  for(int i=0;i<size1;i++)
  {
  	cin>>arr1[i];
  }
}
void readArray2()
{
  cout<<"Enter size of an Array2"<<endl;
  cin>>size2;
  cout<<"Enter the sorted "<<size2<<" elements of an array2"<<endl;
  for(int i=0;i<size2;i++)
  {
  	cin>>arr2[i];
  }
}
void printArray1()
{
  cout<<"Displaying the elements of an array1"<<endl;
  for(int i=0;i<size1;i++)
  {
  	cout<<arr1[i];
   cout<<"\t";
  }
  cout<<endl;
}
void printArray2()
{
  cout<<"Displaying the elements of an array2"<<endl;
  for(int i=0;i<size2;i++)
  {
  	cout<<arr2[i];
   cout<<"\t";
  }
  cout<<endl;
}
void printArray3()
{
  cout<<"Displaying the elements of an merged array"<<endl;
  for(int i=0;i<size;i++)
  {
  	cout<<arr3[i];
   cout<<"\t";
  }
  cout<<endl;
}
void merge()
{
   size = size1+size2;
   int j = 0, k = 0,a,b;
   for(int i = 0 ; i<size ;i++)
   {
   	if(j<size1)
      {
      	a = arr1[j];
      }
      if(k<size2)
      {
      	b = arr2[k];
      }

      if(j!=size1 && k!=size2)
      {
      	if(a<b)
      	{
         	arr3[i] = a;
        		j++;
      	}
      	else
      	{
      		arr3[i] = b;
         	k++;
      	}
       }
       else if(j==size1)
       {
       		arr3[i] = arr2[k];
            k++;
       }
       else if(k==size2)
       {
       		arr3[i] = arr1[j];
            j++;
       }

   }
}

};
int main()
{
	mergeArray ob;
   ob.readArray1();
   ob.readArray2();
   ob.printArray1();
   ob.printArray2();
   ob.merge();
   ob.printArray3();
	getche();
   return 0;
}
