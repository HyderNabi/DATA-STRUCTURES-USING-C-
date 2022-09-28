#include<iostream>
#include<conio.h>
#define MAX 5
//using namespace std;
class QueueStruct
{
    int Queue[MAX];
    int FRONT;
    int REAR;
public:
    QueueStruct()
    {
        FRONT = -1;
        REAR = -1;
    }
    void Enqueue();
    void Dequeue();
    void Display();
};
void QueueStruct::Enqueue()
{
    int elem;
    if((REAR == MAX-1 && FRONT == 0) || (REAR == FRONT-1))
    {
        cout<<"OverFlow";
    }
    else
    {
        cout<<"Enter an element"<<endl;
        cin>>elem;
        if(REAR == -1 && FRONT == -1)
        { 
            REAR = 0;
            FRONT = 0;
        }
        else if(REAR == MAX-1 && FRONT != 0)
        {
            REAR = 0;
        } 
        else 
        {
            REAR++;
        }
        Queue[REAR] = elem;
        cout<<"Element EnQueued Successfully"<<endl;
    }
}
void QueueStruct::Dequeue()
{
    if(FRONT == -1)
    {
        cout<<"UnderFlow";
    }
    else
    {
        if(REAR == FRONT)
        {
            FRONT = -1;
            REAR = -1;
        }
        else if(FRONT == MAX-1)
        {
            FRONT = 0;
        }
        else
        {
            FRONT++;
        }
        cout<<"Dequeued Successfully"<<endl;
    }
}
void QueueStruct::Display()
{
    if(FRONT == -1)
    {
        cout<<"The list is Empty"<<endl;
    }
    else
    {
        int i;
        cout<<"Val\tindex"<<endl;
        i = FRONT;
        do
        {
            cout<<Queue[i]<<"\t"<<i<<endl;
                        
            if(i == MAX -1 && REAR != MAX-1)
            	i = -1;
         } while(i++ != REAR)
    }
};
int main()
{
    QueueStruct Qs;
    int choice;
    while(1)
    {
    cout<<"\n\n";
    cout<<"INPUT 1 FOR ENQUEUE OPERATION"<<endl;
    cout<<"INPUT 2 FOR DEQUEUE OPERATION"<<endl;
    cout<<"INPUT 3 FOR DISPLAY OPERATION"<<endl;
    cout<<"INPUT 0 TO TERMINATE\n"<<endl;
    cin>>choice;
    cout<<"\n\n";

    switch(choice)
    {
        case 1:
            Qs.Enqueue();
            break;
        case 2:
            Qs.Dequeue();
            break;
        case 3:
            Qs.Display();
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
