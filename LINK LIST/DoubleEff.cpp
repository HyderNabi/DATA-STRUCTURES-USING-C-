#include<iostream>
#include<conio>
class node
{
	public:
	int data;
   node *prev;
   node *next;
   //member functions
   node *createList(node *start);
   void displayList(node *start);
   void displayRList(node *start);
   node *insertBeg(node *start);
   node *insertEnd(node *start);
   node *insertAft(node *start);
   //delete//
   node *deleteBeg(node *start);
   node *deleteEnd(node *start);
   node *deleteAft(node *start);
   node *deleteNode(node *start);
};
node *node::createList(node *start)
{
   node *temp,*ptr;
   int i,n;
   cout<<"Enter the number of nodes"<<endl;
   cin>>n;
   cout<<"Enter the "<<n<<" values of nodes"<<endl;
   for(i=0;i<n;i++)
   {
      temp = new node();
   	cin>>temp->data;
      temp->next = NULL;
      if(start == NULL)
      {
      	temp->prev = NULL;
         start = temp;
      }
      else
      {
        ptr = start;
        while(ptr->next != NULL){ ptr = ptr->next;}
        ptr->next = temp;
        temp->prev = ptr;
      }

   }
 return start;

}
//display
void node::displayList(node *start)
{
 	if(start == NULL)
   	cout<<"The List is empty"<<endl;
   else
   {  cout<<"START<=>";
   	while(start != NULL)
      {
      	cout<<start->data<<"<=>";
         start = start->next;
      }
      cout<<"NULL"<<endl;
   }


}
//display reverse
void node::displayRList(node *start)
{
   node *ptr;
 	if(start == NULL)
   	cout<<"The List is empty"<<endl;
   else
   {
   	ptr = start;
   	while(ptr->next != NULL){ ptr = ptr->next;}


      cout<<"ENd<=>";
   	while(ptr != NULL)
      {
      	cout<<ptr->data<<"<=>";
         ptr = ptr->prev;
      }
      cout<<"START";
   }


}
//insert into the begining of the DLL
node *node::insertBeg(node *start)
{
   node *temp = new node();

   if(start == NULL)
   {
   	cout<<"The List is empty"<<endl;
   }
   else
   {
      cout<<"Enter the value of node"<<endl;
   	cin>>temp->data;
      temp->next = start;
      start->prev = temp;
      temp->prev = NULL;
      start = temp;
   }
   return start;
}
//insert at the end of link list

node *node::insertEnd(node *start)
{
   node *temp, *ptr;
   if(start == NULL)
   {
   	cout<<"The List is empty"<<endl;
   }
   else
   {
      cout<<"Enter the value of node"<<endl;
      temp = new node();
   	cin>>temp->data;
      temp->next = NULL;
      ptr = start;
      while(ptr->next != NULL){ptr = ptr->next;}
      ptr->next = temp;
      temp->prev = ptr;
   }
   return start;
}

//insert after the specified node in the DLL
node *node::insertAft(node *start)
{
   node *temp, *ptr;
   int val;
   if(start == NULL)
   {
   	cout<<"The List is empty"<<endl;
   }
   else
   {
      cout<<"Enter the value of node after which insertion should be performed"<<endl;
      cin>>val;
      cout<<"Enter the value of node"<<endl;
      temp = new node();

   	cin>>temp->data;
      ptr = start;

      while(ptr != NULL)
      {

         if(ptr->data == val)
         {
      		temp->next = ptr->next;
      		if(ptr->next != NULL)
      			(temp->next)->prev = temp;
      		ptr->next = temp;
      		temp->prev = ptr;
            break;
         }
         ptr = ptr->next;
      }
      if(ptr == NULL)
      	cout<<"The value is not present in the list"<<endl;
   }
  return start;
}
//delete at the begining of the DLL
node *node::deleteBeg(node *start)
{
   node *temp;

   if(start == NULL)
   {
   	cout<<"The List is empty"<<endl;
   }
   else if(start->next == NULL)
   {
   	temp = start;
      delete(temp);
      start = NULL;
   }
   else
   {
      temp = start;
      start = start->next;
      delete(temp);
      start->prev = NULL;
   }
   return start;
}
//delete at the end of link list

node *node::deleteEnd(node *start)
{
   node *ptr;
   if(start == NULL)
   {
   	cout<<"The List is empty"<<endl;
   }
   else if(start->next == NULL )
   {
   	ptr = start;
   	delete(ptr);
      start = NULL;
   }
   else
   {
      ptr = start;
      while(ptr->next->next != NULL){ptr = ptr->next;}
      delete(ptr->next);
      ptr->next = NULL;
   }
   return start;
}
//delete after the specified node in the DLL
node *node::deleteAft(node *start)
{
   node *temp, *ptr;
   int val;
   if(start == NULL)
   {
   	cout<<"The List is empty"<<endl;
   }
   else
   {
      cout<<"Enter the value of node after which insertion should be performed"<<endl;
      cin>>val;

      ptr = start;

      while(ptr != NULL)
      {

         if(ptr->data == val && ptr->next != NULL)
         {
            temp = ptr -> next;
      		ptr->next = temp->next;
            if(temp->next != NULL)
            	 temp->next->prev = ptr;
            delete(temp);
            break;
         }
         ptr = ptr->next;
      }
      if(ptr == NULL)
      	cout<<"The value is not present in the list OR the value is the last value of list..."<<endl;
   }
  return start;
}
node *node::deleteNode(node *start)
{
    int val;
    node *ptr = start;
    if(start == NULL)
    {
        cout<<"The list is empty"<<endl;
    }
    else
    {
        cout<<"Enter the node to be deleted"<<endl;
        cin>>val;
        while(ptr != NULL)
        {
            if(ptr -> data == val)
            {
                ptr->prev->next = ptr->next;
                if(ptr->next != NULL )
                	ptr->next->prev = ptr->prev;
                delete(ptr);
                cout<<"deleted successfully"<<endl;

                break;
            }


            ptr = ptr -> next;
        }
        if(ptr == NULL)
        {
        	cout<<"The element is not present in the list"<<endl;
        }


    }
    return start;
}
int main()
{
   node *start = NULL;
   node acc;
   int choice;

  while(1)
  {
  	cout<<"\n\n\n";
   cout<<"Enter your Choice::"<<endl;
   cout<<"1. Create List(if Already created the elements will be appended at the end of already created list)."<<endl;
   cout<<"2. Display List."<<endl;
   cout<<"3. Display Reverse List."<<endl;
	cout<<"4. Insert node at the begining of Link List."<<endl;
   cout<<"5. Insert node at the End of the Link List."<<endl;
   cout<<"6. Insert after the specified node in the Link List."<<endl;
   cout<<"7. delete node at the begining of Link List."<<endl;
   cout<<"8. delete node at the End of the Link List."<<endl;
   cout<<"9. delete after the specified node in the Link List"<<endl;
   cout<<"10.delete the specified node in the Link List"<<endl;
   cout<<"0. Exit The Program"<<endl;
   cout<<":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
   cout<<"YOUR CHOICE >>";
   cin>>choice;
   cout<<"\n\n\n";
   switch(choice)
   {
   	case 0:
      		goto exit;
   	case 1:
           start = acc.createList(start);
           break;
      case 2:
           acc.displayList(start);
           break;
      case 3:
      	  acc.displayRList(start);
           break;
      case 4:
      	  start = acc.insertBeg(start);
           break;
      case 5:
      	  start = acc.insertEnd(start);
           break;
      case 6:
      	  start = acc.insertAft(start);
           break;
      case 7:
      	  start = acc.deleteBeg(start);
           break;
      case 8:
      	  start = acc.deleteEnd(start);
           break;
      case 9:
      	  start = acc.deleteAft(start);
           break;
      case 10:
      	  start = acc.deleteNode(start);
           break;
      default:
      		cout<<"Wrong Choice"<<endl;
	}
  }

  exit:
	getche();
   return 0;
}