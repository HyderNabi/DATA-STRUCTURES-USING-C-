#include<iostream>
#include<conio>
#define len 100
class ArrOp
{
	int arr[len],size,pos,value;
   public:
   void readArray();
   void printArray();
   void insertElement();
   void deleteElement();
   void searchElement();
   void sortArray();
};
void ArrOp::readArray()
{
  cout<<"Enter size of an Array"<<endl;
  cin>>size;
  cout<<"Enter "<<size<<" elements of an array"<<endl;
  for(int i=0;i<size;i++)
  {
  	cin>>arr[i];
  }
}
void ArrOp::printArray()
{
  cout<<"Displaying the elements of an array"<<endl;
  for(int i=0;i<size;i++)
  {
  	cout<<arr[i];
   cout<<"\t";
  }
  cout<<endl;
}
void ArrOp::insertElement()
{
  cout<<"Enter the position where you wanna insert an element"<<endl;
  cin>>pos;
  cout<<"Enter the value to be inserted "<<endl;
  cin>>value;
  int i;
  for(i=size;i>=pos;i--)
  {
  	arr[i] = arr[i-1];
  }
  arr[i] = value;
  size++;
  cout<<"Inserted Succesfully"<<endl;
}
void ArrOp::deleteElement()
{
  cout<<"Enter the position where you wanna delete an element"<<endl;
  cin>>pos;
  int i;
  for(i=pos-1;i<size;i++)
  {
  	arr[i] = arr[i+1];
  }
  size--;
  cout<<"Deleted Succesfully"<<endl;
}
void ArrOp::searchElement()
{
  cout<<"Enter the value to be searched "<<endl;
  cin>>value;
  int i;
  for(i=0;i<size;i++)
  {
  	if(arr[i] == value)
   {
   	cout<<"The first occurence of Entered value is at position "<<(i+1)<<endl;
      break;
   }
   if(i == size)
   {
   	cout<<"Value not present"<<endl;
   }
  }

}
void ArrOp::sortArray()
{
 	cout<<"Sorting in ascending order"<<endl;
   int i,j,temp;
   for(i=0;i<size-1;i++)
   {
     for(j=i+1;j<size;j++)
     {
     	if(arr[i] > arr[j])
      {
      	temp = arr[i];
         arr[i] = arr[j];
         arr[j] = temp;
      }

     }
   }
}
int main()
{
   ArrOp elm;
   elm.readArray();
   elm.printArray();
	elm.insertElement();
   elm.printArray();
   elm.deleteElement();
   elm.printArray();
   elm.searchElement();
   elm.sortArray();
   elm.printArray();
	getche();
   return 0;
}