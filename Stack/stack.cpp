#include<iostream>
#include<conio.h>
//using namespace std;
class cell
{
  public:
    int val;
    cell *next;
};
class stackOp:public cell
{
    cell *top;
    public:
    stackOp()
    {
        top = NULL;
    }
    void push();
    void pop();
    void peek();
    void display();
} ;
//push the cell in the stack
void stackOp::push()
{
    cout<<"Enter the value of cell"<<endl;
    cell *temp = new cell();
    cin>>temp->val;
    if(top == NULL)
    {
        temp -> next = NULL;
        top = temp;
        top -> next = NULL;
    }
    else
    {
        temp -> next = top;
        top = temp;
    }
    cout<<"cell pushed successfully at the top"<<endl;
}
//pop the cell out from the stack
void stackOp::pop()
{
    if(top == NULL)
    {
        cout<<"UNDERFLOW"<<endl;
    }
    else
    {
        cell *ptr;
        ptr = top;
        top = top -> next;
        delete(ptr);
        cout<<"top of the stack poped successfully"<<endl;
    }
}
void stackOp::peek()
{
     if(top == NULL)
    {
        cout<<"UNDERFLOW"<<endl;
    }
    else
    {
        cout<<"Top = "<<top->val<<endl;
    }
}
void stackOp::display()
{
     if(top == NULL)
    {
        cout<<"UNDERFLOW"<<endl;
    }
    else
    {
        cell *ptr;
        ptr = top;
        while(ptr != NULL)
        {
            cout<<ptr->val<<endl;
            ptr = ptr->next;
        }
    }
}
int main()
{
    stackOp op;
    int choice;
while(1)
{
    cout<<"\n\n";
    cout<<"INPUT 1 FOR PUSH OPERATION"<<endl;
    cout<<"INPUT 2 FOR POP OPERATION"<<endl;
    cout<<"INPUT 3 FOR peek OPERATION"<<endl;
    cout<<"INPUT 4 FOR DISPLAY OPERATION"<<endl;
    cout<<"INPUT 0 TO TERMINATE\n"<<endl;
    cin>>choice;
    cout<<"\n\n";

    switch(choice)
    {
        case 1:
            op.push();
            break;
        case 2:
            op.pop();
            break;
        case 3:
            op.peek();
            break;
        case 4:
            op.display();
            break;
        case 0:
            goto out;
        default:
            cout<<"Wrong Input"<<endl;
    }
}
    out:
    getche();
    return 0;
}