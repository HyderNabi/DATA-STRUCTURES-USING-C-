#include<iostream>
#include<conio>
class node
{
  int i;
  int j;
  int val;
  node *next;
  public:
  node *readnStore(node *start);
  void display(node *start);
};
node *node::readnStore(node *start)
{
	int elem,a,b,rows,cols,total = 0;
   node *last;
   node *temp = new node();
	cout<<"Enter dimensions of the matrix"<<endl;
   cout<<"Enter Rows = ";
   cin>>rows;
   cout<<"Enter Cols = ";
   cin>>cols;

   //first node;
   temp->i = rows;
   temp->j = cols;
   temp->val = 0;
   start = temp;
   start->next = NULL;
   last = start;

   cout<<"Enter "<<rows<<"*"<<cols<< "Elements of the matrix"<<endl;
   for(a=0; a<rows; a++)
   {
   	for(b=0; b<cols; b++)
      {
       	cin>>elem;
         if(elem != 0)
         {
            temp = new node();
            temp->i = a;
            temp->j = b;
            temp->val = elem;
            temp->next = NULL;
            last->next = temp;
            last = last->next;
            total++;

         }
      }
   }
   start->val = total;
   return start;

}
void node::display(node *start)
{
	if(start == NULL)
   {
   	cout<<"The list is empty"<<endl;
   }
   else
   {
      while(start != NULL)
      {
      	cout<<start->i<<"\t"<<start->j<<"\t"<<start->val<<endl;
         start = start->next;
      }
   }
}
int main()
{
node *start = NULL;
node ob;
start = ob.readnStore(start);
ob.display(start);
getche();
return 0;
}