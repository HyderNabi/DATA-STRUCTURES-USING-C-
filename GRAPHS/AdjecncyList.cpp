#include<iostream>
#include<conio.h>
#define LEN 10
using namespace std;
int n;
class graph
{
    char data;
    graph *next;
public:
    graph *createList(graph *list[])
    {
        graph *trv,*temp;
        int neigh;
         cout<<"Enter the number of nodes"<<endl;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            list[i];
            cout<<"Enter the no of neighbours of node "<<i<<endl;
            cin>>neigh;
            cout<<"Enter the "<<neigh<<" nodes of the "<<i<<endl;
            for(int j=1;j<=neigh;j++)
            {
                        temp = new graph();
                        cin>>temp->data;
                        temp->next = NULL;
                        if(list[i] == NULL)
                        {
                                list[i] = temp;
                        }
                        else
                        {
                                trv = list[i];
                                while(trv->next!=NULL)
                                {
                                        trv = trv->next;
                                }
                                trv->next = temp;
                        }
                }
        }

        return *list;
    }

    void display(graph *list[])
    {
            char val = 65;
        for(int i=1;i<=n;i++)
        {
                cout<<val<<"=>";
                val++;
                while(list[i] !=NULL)
                {
                        cout<<list[i]->data<<"---->";
                        list[i] = list[i]->next;
                }
                cout<<"NULL";
                cout<<endl;

        }
    }


};

int main()
{
    graph ls;
    graph *list[LEN] = {NULL};
    *list  = ls.createList(list);
    ls.display(list);



}

