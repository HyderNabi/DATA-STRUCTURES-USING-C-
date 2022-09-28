#include<iostream>
#include<conio.h>
#define MAX 30
using namespace std;
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
    if(REAR == MAX-1)
    {
        cout<<"OverFlow";
    }
    else
    {
        cout<<"Enter an element"<<endl;
        cin>>elem;
        if(REAR == -1 && FRONT == -1){ REAR++;FRONT++;} else {REAR++;}
        Queue[REAR] = elem;
        cout<<"Element EnQueued Successfully"<<endl;
    }
}
void QueueStruct::Dequeue()
{
    if(FRONT == -1 && REAR == -1)
    {
        cout<<"UnderFlow";
    }
    else
    {
        if(REAR == FRONT)
        {
            FRONT--;
            REAR--;
        }
        else
        {
            int i;
            for(i=FRONT;i<REAR;i++)
            {
                Queue[i] = Queue[i+1];
            }
            REAR--;
        }
        cout<<"Dequeued Successfully"<<endl;
    }
}
void QueueStruct::Display()
{
    if(FRONT == -1 && REAR == -1)
    {
        cout<<"The list is Empty"<<endl;
    }
    else
    {
        int i;
        for(i=FRONT;i<=REAR;i++)
        {
            cout<<Queue[i]<<endl;
        }
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
