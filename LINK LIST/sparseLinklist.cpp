#include<iostream>
#include<conio>
class node
{
	public:
	int iVal;
   int jVal;
   int val;
   node *next;
   //member functions
   node *matToLinkList(node *start,int ar[5][5]);
   void display(node *start);
};
node *node::matToLinkList(node *start,int ar[5][5])
{
   node *temp,*last;
   int i,j;
   for(i=0;i<5;i++)
   {
   	for(j=0;j<5;j++)
      {
       	if(ar[i][j] != 0)
         {
           temp = new node();
           temp->iVal = i;
           temp->jVal = j;
           temp->val = ar[i][j];
           temp->next = NULL;
         	if(start->next == NULL)
            {
               start->next = temp;
               last = temp;
            }
            else
            {
            	last->next = temp;
               last = temp;
            }
         }

      }
   }
   return start;
}

void node::display(node *start)
{
	if(start == NULL)
   {
   	cout<<"-=Empty List=-"<<endl;
   }
   else
   {
   	while(start != NULL)
		{
       cout<<start->iVal<<"\t"<<start->jVal<<"\t"<<start->val<<endl;
       start = start->next;
      }
   }
}

int main()
{
 node *start = new node();
 node ob;
 int i,j,size=0;
 int arr[5][5] = {    {0,0,0,1,0},
    						 {0,0,5,0,0},
                      {0,6,0,0,0},
                      {0,0,0,0,9},
                      {4,0,0,0,0},
                };
 for(i=0;i<5;i++)
 	for(j=0;j<5;j++)
   	if(arr[i][j] != 0){ size++; }

 start->iVal = 5;
 start->jVal = 5;
 start->val = size;
 start->next = NULL;
 start = ob.matToLinkList(start,arr);
 ob.display(start);

 getche();
 return 0;
}
