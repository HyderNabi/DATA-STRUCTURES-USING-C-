#include<iostream>
#include<conio.h>
#define LEN 50
//using namespace std;
class stack
{
    int arr[LEN];
    int size;
    public:
    stack()
    {
        size = -1;
    }
    void push()
    {
        if(size == LEN-1)
        {
            cout<<"OverFlow"<<endl;
        }
        else
        {
            int elm;
            cout<<"Enter the Element"<<endl;
            cin>>elm;
            size++;
            arr[size] = elm;
            cout<<"Element inserted successfully"<<endl;
        }
     }

     void pop()
     {
         if(size ==-1)
         {
             cout<<"UNDERFLOW"<<endl;
         }
         else
         {
             cout<<"Element poped successfully. The value is "<<arr[size]<<endl;
             size--;
         }

     }
     void display()
     {
         if(size == -1)
         {
             cout<<"List is Empty"<<endl;
         }
         else
         {
             for(int i = size; i >= 0; i--)
             {
                 cout<<arr[i]<<endl;
             }
         }
     }
     void peek()
     {
         if(size == -1)
         {
             cout<<"List is Empty"<<endl;
         }
         else
         {
             cout<<"TOP = "<<arr[size];
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