#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
//Author: Hyder Nabi
//20-june-2021 12:03:23
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
      node *insertBefNode(node *start);
      node *insertAfNode(node *start);
      //delete
      node *deleteBeg(node *start);
      node *deleteEnd(node *start);
      node *deleteAfNode(node *start);
      node *deleteNode(node *start);
      node *deleteList(node *start);
      //sort
      node *sortList(node *start);
      node *reverseList(node *start);

};
//CREATE LINK LIST
node *node::create(node *start)
{
       int n,val,index;
       node *temp,*trv;
       cout<<"Enter the number of nodes"<<endl;
       cin>>n;
       cout<<"Enter the "<<n<<" nodes of the Link List"<<endl;
       for(index=0; index<n; index++)
       {
       	temp = new node;
       	cin>>val;
       	if(start == NULL)
         {
           temp->data = val;
           temp->next = NULL;
           start = temp;
         }
         else
         {
            trv = start;
         	while(trv->next != NULL){ trv = trv->next; }
            temp->data = val;
            trv->next = temp;
            temp->next = NULL;
         }
       }
	return start;
}
//TRAVERSAL
void node::display(node *start)
{

	if(start == NULL)
   {
   	cout<<"The list is empty"<<endl;
   }else
   {
   	cout<<"START->";
   	while(start != NULL)
      {
      	cout<<start->data<<"->";
         start = start->next;
      }
      cout<<"NULL"<<endl;
   }

}
//inserting at the begining of the list
node *node::insertBeg(node *start)
{
   node *temp = new node;
   cout<<"INSERTION AT THE BEGINING OF THE LINK LIST"<<endl;
	cout<<"Enter the value to be inserted at the begining of list"<<endl;
   cin>>temp->data;
   temp->next = start;
   start = temp;
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
   	temp -> next = NULL;
   	start = temp;
   }
   else
   {
   	trv = start;
   	while(trv->next != NULL){ trv = trv->next; }
   	trv->next = temp;
   	temp->next = NULL;
   }
   return start;
}
//insertion before the specified node
node *node::insertBefNode(node *start)
{
	node *temp,*trv,*prv;
   int val,node_value;
	cout<<"INSERTION BEFORE THE SPECIFIED NODE IN THE LINK LIST"<<endl;
   cout<<"Enter the value of node before which you wanna insert your node"<<endl;
   cin>>node_value;
   cout<<"Enter value to be inserted before "<<node_value<<endl;
   cin>>val;
   temp = new node;
   temp->data = val;
   if(start == NULL)
   {
   	cout<<"The list is empty!!! Better create the list first"<<endl;
   }
   else
   {
   	trv = start;
   	while(trv->data != node_value )
   	{
   		prv = trv;
   		trv = trv->next;
         if(trv == NULL)
         {
            break;
         }
   	}
   	if(trv != NULL)
   	{
      	if(trv == start)
         {
           temp->next = start;
           start = temp;
         }
         else
         {
   		  prv->next = temp;
   		  temp->next = trv;
         }
		}
   	else
   	{
   		cout<<"There is no such node in the list"<<endl;
   	}
   }
   return start;

}

//insertion After the specified node
node *node::insertAfNode(node *start)
{
	node *temp,*trv,*prv;
   int val,node_value;
	cout<<"INSERTION AFTER THE SPECIFIED NODE IN THE LINK LIST"<<endl;
   cout<<"Enter the value of node after which you wanna insert your node"<<endl;
   cin>>node_value;
   cout<<"Enter value to be inserted after "<<node_value<<endl;
   cin>>val;
   temp = new node;
   temp->data = val;
   if(start == NULL)
   {
   	cout<<"The list is empty!!! Better create the list first"<<endl;
   }
   else
   {

      trv = start;
      prv = trv->next;
   	while(trv->data != node_value )
   	{
   		trv = prv;
         if(trv == NULL)
         {
         	break;
         }
   		prv = prv->next;

   	}
   	if(trv != NULL)
   	{
           		trv->next = temp;
   		  		temp->next =prv;
		}
   	else
   	{
   		cout<<"There is no such node in the list"<<endl;
   	}
   }
   return start;

}
//delete at begining;;
node *node::deleteBeg(node *start)
{
   node *ptr;
   cout<<"DELETE THE BEGINING OF THE LIST"<<endl;
   if(start == NULL)
	{
   	cout<<"Empty List(Underflow)"<<endl;
   }
   else
   {
      ptr = start;
   	start = start->next;
      delete(ptr);
      cout<<"Deleted Successfully"<<endl;
   }
   return start;
}
//delete at end;
node *node::deleteEnd(node *start)
{
   node *ptr;
   cout<<"DELETE THE END OF THE LIST"<<endl;
   if(start == NULL)
	{
   	cout<<"Empty List(Underflow)"<<endl;
   }
   else if(start->next == NULL)
   {
   	delete(start);
      start = NULL;
       cout<<"Deleted Successfully"<<endl;
   }
   else
   {
      ptr = start;
      while((ptr->next)->next != NULL){ ptr = ptr->next; }
      delete(ptr->next);
      ptr->next = NULL;
      cout<<"Deleted Successfully"<<endl;
   }
   return start;
}

//deletion After the specified node
node *node::deleteAfNode(node *start)
{
	node *trv,*prv;
   int node_value;
	cout<<"DELETION AFTER THE SPECIFIED NODE IN THE LINK LIST"<<endl;
   cout<<"Enter the value of node after which you wanna delete your node"<<endl;
   cin>>node_value;
   if(start == NULL)
   {
   	cout<<"The list is empty.(Underflow)."<<endl;
   }
   else
   {
   	trv = start;
      prv=start->next;
   	while(trv->data != node_value )
   	{
         trv = trv->next;
      	prv = prv->next;

   		if(prv == NULL)
         {
            break;
         }
   	}
   	if(prv != NULL)
   	{

   		  trv->next = prv->next;
           delete(prv);
           cout<<"Deleted Successfully"<<endl;

		}
      else
   	{
      	if(trv->data == node_value)
           cout<<"Specified node is the Last node in the list!!! Deletion cannot be performed!!"<<endl;
         else
   		  cout<<"There is no such node in the list"<<endl;
   	}
   }
   return start;

}
//delete the specified node in the link list
node *node::deleteNode(node *start)
{
	int val;
   node *trv,*prv;
   if(start == NULL)
   {
   	cout<<"The list is empty(Underflow)"<<endl;
   }
   else
   {
   	cout<<"Enter the value to be deleted from the link list"<<endl;
      cin>>val;
      if(start->data == val)
      {
      	start = deleteBeg(start);
         return start;
      }
      else
      {  trv = start->next;
      	while(trv->data != val)
         {
            prv = trv;
            trv = trv->next;
            if(trv == NULL){ break;}

         }
         if(trv != NULL)
         {
         	prv->next = trv->next;
            delete(trv);
            cout<<"deleted successfully"<<endl;
         }
         else
         {
         	cout<<"the value specified is not in the list"<<endl;
         }


      }
   }
 return start;

}


//delete the whole list
node *node::deleteList(node *start)
{
   node *ptr;
 	if(start == NULL)
   {
   	cout<<"List is already Empty"<<endl;
   }
   else
   {
   	ptr = start;
      while(ptr != NULL)
      {
        ptr = deleteBeg(ptr);
      }
      start = ptr;
   }
 return start;
}
//sort the link list
node *node::sortList(node *start)
{
   node *i,*j;
   int temp;
	if(start == NULL)
   {
   	cout<<"The List is empty(Underflow)"<<endl;
   }
   else
   {  i = start;
   	while(i->next!=NULL)
      {
      	j = i->next;
      	while(j!=NULL)
         {
         	if(i->data > j->data)
            {
            	temp = i->data;
               i->data = j->data;
               j->data = temp;
            }
            j = j->next;
         }
         i = i->next;
      }

   }
   return start;
}

 //reverse the list
 node *node::reverseList(node *start)
 {
 	node *cur, *prv;
 	if(start == NULL)
   {
   	cout<<"Empty List"<<endl;
   }
   else
   {
   	cur = start;
      prv = start;
      start = NULL;
      while(prv != NULL)
      {
       	cur = cur->next;
         prv->next = start;
         start = prv;
         prv = cur;
      }
   }
   return start;
 }
int main()
{
   int choice;
	//creating START node
   node *start = NULL;
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
   cout<<"5. Insert node before the specified node."<<endl;
   cout<<"6. Insert node after the specified node."<<endl;
   cout<<"7. delete node at the begining of Link List."<<endl;
   cout<<"8. delete node at the End of the Link List."<<endl;
   cout<<"9. delete node after the specified node."<<endl;
   cout<<"10. delete the specified node in the link list."<<endl;
   cout<<"11. Delete the Link List(Truncate)."<<endl;
   cout<<"12. Sort the link list(Bubble Sort)"<<endl;
   cout<<"13. Reverse the link list"<<endl;
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
      	   start = list.insertBefNode(start);
            break;
      case 6:
            start = list.insertAfNode(start);
            break;
      case 7:
      		start = list.deleteBeg(start);
            break;
      case 8:
      		start = list.deleteEnd(start);
            break;
      case 9:
      		start = list.deleteAfNode(start);
            break;
      case 10:
      		start = list.deleteNode(start);
            break;
      case 11:
      		start = list.deleteList(start);
            break;
      case 12:
      		start = list.sortList(start);
            break;
      case 13:
      		start = list.reverseList(start);
            break;
      default:
      		cout<<"Wrong Choice"<<endl;
	}
  }

  getche();
return 0;
}