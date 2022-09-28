#include<iostream>
#include<conio.h>
#define LEN 20
using namespace std;
class Node
{
        int data;
        Node *next;
public:
        Node *insert(Node *node,int value)
        {
                Node *temp,*trv;
                temp = new Node();
                temp->data = value;
                temp->next = NULL;
                if (node == NULL)
                {
                        node = temp;
                }
                else
                {
                        trv = node;
                        while(trv->next != NULL)
                        {
                                trv = trv->next;
                        }
                        trv->next = temp;
                }
                cout<<"Value = "<<value<<", in a Hash Table Inserted Successfully"<<endl;
                return node;


        }


        //display()
        void display(Node *node[],int Length)
        {
                int i;
                for(i = 0;i<Length;i++)
                {
                        while(node[i]!=NULL)
                        {
                                cout<<node[i]->data<<"--->";
                                node[i] = node[i]->next;
                        }
                        cout<<"NULL"<<endl;
                }
        }
};

class Hash
{
        Node *Hash_Table[LEN];
        int Length;
public:
        Hash(int len)
        {
                Length = len;

                int i;
                for(i=0;i<Length;i++)
                        Hash_Table[i] = NULL;
        }


        void Hashing()
        {
                Node node;

                int x,index,contd = 1;
                while (contd)
                {
                        cout<<"Enter Value = ";
                        cin>>x;
                        if(x == -1)
                                break;
                        //Hash Function = Division

                        index = H(x);
                        Hash_Table[index] = node.insert(Hash_Table[index],x);
                }
                node.display(Hash_Table,Length);
        }
        int H(int x)
        {
                return x%Length;
        }

};

int main()
{
        int Length;
        cout<<"Enter the Length of Hash table = ";
        cin>>Length;
        Hash h(Length);
        h.Hashing();
        getche();
        return 0;
}
