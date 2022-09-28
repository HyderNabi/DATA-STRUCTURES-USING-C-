#include<iostream>
#include<conio>
class Node
{
    int coff;
    int pow;
  public:
    Node *next;
    Node *createpoly(Node *start);
    void display(Node *start);
    Node *Addition(Node *start1, Node *start2);
    Node *Multiplication(Node *start1, Node *start2);
    Node *Delete(Node *start, Node *node);
};
Node *Node::createpoly(Node *start)
{
    Node *temp,*last;
    int terms;
    cout<<"Enter the terms of a Polynomial"<<endl;
    cin>>terms;
    while(terms)
    {
        temp = new Node();
        cout<<"Enter the cofficient"<<endl;
        cin>>temp->coff;
        cout<<"Enter the power"<<endl;
        cin>>temp->pow;
        temp->next = NULL;
        if(start == NULL)
        {
            start = temp;
            last = start;
        } 
        else
        {
            last->next = temp;
            last = temp;
        }
        terms--;

    }
    return start;
}
void Node::display(Node *start)
{
    if(start == NULL)
    {
        cout<<"Empty List"<<endl;
    }
    else
    {
        while(start != NULL)
        {
            cout<<start->coff;
            if(start->pow != 0){ cout<<"X^"; }
        		if(start->pow != 1 && start->pow != 0){cout<<start->pow; }
            start = start->next;
            if(start != NULL)
            {
            	if(start->coff >= 0 ){ cout<<"+";}
            };
        }
    }
}
//Addition of two Polynomials
 Node *Node::Addition(Node *start1, Node *start2)
 {
     Node *st1,*st2,*temp,*last;
     Node *start3 = NULL;
     st1 = start1;
     st2 = start2;
     while(st1 != NULL && st2 != NULL)
     {
         if(st1->pow == st2->pow)
         {
             temp = new Node();
             temp->coff = (st1->coff + st2->coff);
             temp->pow = st1->pow;
             temp->next = NULL;
             if(start3 == NULL)
             {
                 start3 = temp;
                 last = start3;
             }
             else
             {
                 last->next = temp;
                 last = temp;
             }
             st1 = st1->next;
             st2 = st2->next;
         }
         else if(st1->pow > st2->pow)
         {
             temp = new Node();
             temp->coff = st1->coff;
             temp->pow = st1->pow;
             temp->next = NULL;
             if(start3 == NULL)
             {
                 start3 = temp;
                 last = start3;
             }
             else
             {
                 last->next = temp;
                 last = temp;
             }
             st1 = st1->next;
         }
         else
         {
             temp = new Node();
             temp->coff = st2->coff;
             temp->pow = st2->pow;
             temp->next = NULL;
             if(start3 == NULL)
             {
                 start3 = temp;
                 last = start3;
             }
             else
             {
                 last->next = temp;
                 last = temp;
             }
             st2 = st2->next;
         }
     }
     //TODO: {if size of first polynomials is greater than 2nd polynomial}
     while(st1 != NULL)
     {
      		 temp = new Node();
             temp->coff = st1->coff;
             temp->pow = st1->pow;
             temp->next = NULL;
             if(start3 == NULL)
             {
                 start3 = temp;
                 last = start3;
             }
             else
             {
                 last->next = temp;
                 last = temp;
             }
             st1 = st1->next;

     }
     //TODO: {if size of 2nd  polynomials is greater than 1st polynomial}
     while(st2 != NULL)
     {
     		 temp = new Node();
             temp->coff = st2->coff;
             temp->pow = st2->pow;
             temp->next = NULL;
             if(start3 == NULL)
             {
                 start3 = temp;
                 last = start3;
             }
             else
             {
                 last->next = temp;
                 last = temp;
             }
             st2 = st2->next;
     }
    return start3;
 }
//Multiplication of Two Polynomials
Node *Node::Multiplication(Node *start1, Node *start2)
 {
     Node *st1,*st2,*temp,*last;
     Node *inter=NULL;
     st1 = start1;
     while(st1 != NULL)
     {
          st2 = start2;
         while(st2 !=NULL)
         {
             temp = new Node();
             temp->coff = (st1->coff * st2->coff);
             temp->pow = (st1->pow + st2->pow);
             temp->next = NULL;

             if(inter  == NULL)
             {
                 inter = temp;
                 last = inter;

             }
             else
             {
                 last->next = temp;
                 last = temp;
             }
             st2 = st2->next;

         }
         st1 = st1->next;

     }
     st1 = inter;
     while(st1 != NULL)
     {
        st2 = st1->next;
         while(st2 != NULL)
         {

             if(st2->pow == st1->pow)
             {
                 st1->coff = (st1->coff+st2->coff);
                 st2 = Delete(inter, st2);

             }
             else
             {
             	st2= st2->next;
             }
         }
         st1 = st1->next;
     }
    return inter;
 }
 //this function is used during multiplication
 Node *Node::Delete(Node *start , Node *node)
 {
     Node *t1,*t2;
     t1 = start;
     while(t1 != node)
     {
         t2 = t1;
         t1 = t1->next;
     }
     t2->next = t1->next;
     delete(t1);
     return(t2->next);

 }
int main()
{
    Node *start1 = NULL;
    Node *start2 = NULL;
    Node *start3;
    Node *start4;
    Node node;
    cout<<"Create 1st Polynomial"<<endl;
    start1 = node.createpoly(start1);
    cout<<"Create 2nd Polynomial"<<endl;
    start2 = node.createpoly(start2);
    cout<<"Displaying 1st Polynomial"<<endl;
    node.display(start1);
    cout<<"\nDisplaying 2nd Polynomial"<<endl;
    node.display(start2);
    cout<<"\n:::::::::::Addition:::::::::::"<<endl;
    start3 = node.Addition(start1,start2);
    node.display(start3);
    cout<<"\n:::::::::::Multiplication:::::::::::"<<endl;
    start4 = node.Multiplication(start1,start2);
    node.display(start4);
    getche();
    return(0);
}