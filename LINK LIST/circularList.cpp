#include<iostream>
#include<conio>
#include<stdlib>
//Author: Hyder Nabi
class node
{
   public:
		int data;
   	node *next;
      //member functions
      node *create(node *start);
      void display(node *start);
      //insert
      node *insertBeg(node *start);
      node *insertEnd(node *start);
      //delete
      node *deleteBeg(node *start);
      node *deleteEnd(node *start);
};
//CREATE LINK LIST
node *node::create(node *start)
{
       int n,val,index;
       node *temp;
       static node *end = NULL;
       cout<<"Enter the number of nodes"<<endl;
       cin>>n;
       cout<<"Enter the "<<n<<" nodes of the Link List"<<endl;
       for(index=0; index<n; index++)
       {
       	temp = new node;
       	cin>>val;
         temp->data = val;
       	if(start == NULL)
         {
           start = temp;
           end = start;
           end->next = start;
         }
         else
         {
            end->next = temp;
            temp->next = start;
            end = temp;
         }
       }
	return start;
}
//TRAVERSAL
void node::display(node *start)
{
    node *ptr;
	if(start == NULL)
   {
   	cout<<"The list is empty"<<endl;
   }else
   {
      cout<<start->data<<"->";
   	ptr = start->next;
   	while(ptr != start)
      {
      	cout<<ptr->data<<"->";
         ptr = ptr->next;
      }
      cout<<ptr->data<<"(START)";

   }

}
//inserting at the begining of the list
node *node::insertBeg(node *start)
{
   node *temp = new node;
   node *trv = start;
   cout<<"INSERTION AT THE BEGINING OF THE CIRCULAR LINK LIST"<<endl;
	cout<<"Enter the value to be inserted at the begining of list"<<endl;
   cin>>temp->data;
   while(trv->next != start){ trv = trv->next ;}
   temp->next = start;
   start = temp;
   trv->next = temp;
   return start;
}
//inserting at the end of the list
node *node::insertEnd(node *start)
{
   node *temp = new node;
   node *trv;
   cout<<"INSERTION AT THE END OF THE LINK LIST"<<endl;
	cout<<"Enter the value to be inserted at the end of list"<<endl;
   cin>>temp->data;
   if(start == NULL)
   {
      start = temp;
   	temp -> next = start;

   }
   else
   {
   	trv = start;
   	while(trv->next != start){ trv = trv->next; }
   	trv->next = temp;
   	temp->next = start;
   }
   return start;
}

//delete at begining;;
node *node::deleteBeg(node *start)
{
   node *end;
   cout<<"DELETE THE BEGINING OF THE CIRCULAR LINK LIST"<<endl;
   if(start == NULL)
	{
   	cout<<"Empty List(Underflow)"<<endl;
   }
   else
   {
   	end = start;
   	while(end->next != start){ end = end->next; }
      end->next = start->next;
      delete(start);
      start = end->next;
      cout<<"Deleted Successfully"<<endl;
   }
   return start;
}
//delete at end;
node *node::deleteEnd(node *start)
{
   node *ptr;
   cout<<"DELETE THE END OF THE CIRULAR LINKLIST"<<endl;
   if(start == NULL)
	{
   	cout<<"Empty List(Underflow)"<<endl;
   }
   else if(start->next == start)
   {
   	delete(start);
      start = NULL;
       cout<<"Deleted Successfully"<<endl;
   }
   else
   {
      ptr = start;
      while((ptr->next)->next != start){ ptr = ptr->next; }
      delete(ptr->next);
      ptr->next = start;
      cout<<"Deleted Successfully"<<endl;
   }
   return start;
}


int main()
{
   int choice;
	//creating START node
   node *start;
   start = NULL;
    /*create list object to access member functions of the class NODE */
   node list;
  while(1)
  {
  	cout<<"\n\n\n";
   cout<<"Enter your Choice::"<<endl;
   cout<<"1. Create List(if Already created the elements will be appended at the end of already created list)."<<endl;
   cout<<"2. Display List."<<endl;
   cout<<"3. Insert node at the begining of Link List."<<endl;
   cout<<"4. Insert node at the End of the Link List."<<endl;
   cout<<"5. delete node at the begining of Link List."<<endl;
   cout<<"6. delete node at the End of the Link List."<<endl;
   cout<<"0. Exit The Program"<<endl;
   cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
   cout<<"YOUR CHOICE >>";
   cin>>choice;
   cout<<"\n\n\n";
   switch(choice)
   {
   	case 0:
      		exit(0);
            break;
   	case 1:
           start = list.create(start);
           break;
      case 2:
           list.display(start);
           break;
      case 3:
      	  start = list.insertBeg(start);
           break;
      case 4:
            start = list.insertEnd(start);
            break;
      case 5:
      	   start = list.deleteBeg(start);
            break;
      case 6:
      		start = list.deleteEnd(start);
            break;
      default:
      		cout<<"Wrong Choice"<<endl;
	}
  }

getche();
return 0;
}