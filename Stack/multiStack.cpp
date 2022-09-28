//Author: Hyder Nabi
//Roll No.: 05
#include<iostream>
#include<conio.h>
#define LEN 50
//using namespace std;
class stack
{
    int arr[LEN];
    int top1,top2;
    public:
    stack()
    {
        top1 = -1;
        top2 = LEN;
    }
    void push1()
    {
        if(top1 == top2-1)
        {
            cout<<"OverFlow"<<endl;
        }
        else
        {
            int elm;
            cout<<"Enter the Element"<<endl;
            cin>>elm;
            top1++;
            arr[top1] = elm;
            cout<<"Element inserted successfully at the top of Stack1"<<endl;
        }
     }
     void push2()
    {
        if(top2 == top1+1)
        {
            cout<<"OverFlow"<<endl;
        }
        else
        {
            int elm;
            cout<<"Enter the Element"<<endl;
            cin>>elm;
            top2--;
            arr[top2] = elm;
            cout<<"Element inserted successfully at the top of Stack2"<<endl;
        }
     }

     void pop1()
     {
         if(top1 == -1)
         {
             cout<<"UNDERFLOW"<<endl;
         }
         else
         {
             cout<<"Element poped successfully from Stack1. The value is "<<arr[top1]<<endl;
             top1--;
         }

     }
     void pop2()
     {
         if(top2 == LEN)
         {
             cout<<"UNDERFLOW"<<endl;
         }
         else
         {
             cout<<"Element poped successfully from Stack2. The value is "<<arr[top2]<<endl;
             top2++;
         }

     }
     void display1()
     {
         if(top1 == -1)
         {
             cout<<"List is Empty"<<endl;
         }
         else
         {
             for(int i = top1; i >= 0; i--)
             {
                 cout<<arr[i]<<endl;
             }
         }
     }
     void display2()
     {
         if(top2 == LEN)
         {
             cout<<"List is Empty"<<endl;
         }
         else
         {
             for(int i = top2; i < LEN; i++)
             {
                 cout<<arr[i]<<endl;
             }
         }
     }
  
};
int main()
{
    stack op;
    int choice;
while(1)
{
    cout<<"\n\n";
    cout<<"INPUT 1 FOR PUSH OPERATION FOR STACK1"<<endl;
    cout<<"INPUT 2 FOR PUSH OPERATION FOR STACK2"<<endl;
    cout<<"INPUT 3 FOR POP OPERATION FOR STACK1"<<endl;
    cout<<"INPUT 4 FOR POP OPERATION FOR STACK2"<<endl;
    cout<<"INPUT 5 FOR DISPLAY OPERATION FOR STACK1"<<endl;
    cout<<"INPUT 6 FOR DISPLAY OPERATION FOR STACK2"<<endl;
    cout<<"INPUT 0 TO TERMINATE\n"<<endl;
    cin>>choice;
    cout<<"\n\n";

    switch(choice)
    {
        case 1:
            op.push1();
            break;
        case 2:
            op.push2();
            break;
        case 3:
            op.pop1();
            break;
        case 4:
            op.pop2();
            break;
        case 5:
            op.display1();
            break;
        case 6:
            op.display2();
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