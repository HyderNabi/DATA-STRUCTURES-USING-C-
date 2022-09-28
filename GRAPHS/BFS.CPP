#include<iostream>
#include<conio.h>
#define LEN  20
using namespace std;
class BFS{
        int AdjMat[LEN][LEN];
        int V;
        int Queue[LEN];
        int Front,Rear;
        int Status[LEN];
        int parent[LEN];
        /*
        Status
        1-> Ready State
        2-> Waiting State (In the Queue)
        3-> Processed State
        */
public:
        BFS(int data[LEN][LEN],int V)
        {
                int i,j;
                Front = -1;
                Rear = -1;
                this->V  = V;
                 for(i = 0;i<V;i++)
                {
                        Status[i] = 1;
                        for(j=0;j<V;j++)
                        {
                                AdjMat[i][j] = data[i][j];

                        }
                }
        }


        void process()
        {
                int node,i;
                int value,in;
                bool flag;

                cout<<"Enter value of initial node of the graph = ";
                cin>>in;
                cout<<"Enter value of Node to be searched = ";
                cin>>value;


                enqueue(in);
                parent[in] = -1;
                Status[in] = 2;
                while(Front<=Rear)
                {
                        node = dequeue();
                        Status[node] = 3;
                        if(node == value)
                        {
                                displayPath(node);
                                cout<<node;
                                flag = true;
                                break;
                        }
                        else
                        {
                                for(i=0;i<V;i++)
                                {
                                        if(AdjMat[node][i] == 1 && Status[i] == 1)
                                        {
                                                enqueue(i);
                                                parent[i] = node;
                                                Status[i] = 2;
                                        }
                                }
                                flag = false;
                        }

                }
                if(flag == false)
                {
                        cout<<"The value is not found"<<endl;
                }
        }

        void displayPath(int node)
        {
                if(parent[node] == -1)
                        return;
                else
                        displayPath(parent[node]);
                        cout<<parent[node]<<"--->";

        }



        void enqueue(int elem)
        {
                if(Rear == LEN)
                {
                        cout<<"overflow";
                }
                else
                {
                        if(Rear == -1)
                        {
                                Front++;
                                Queue[++Rear] = elem;
                        }
                        else
                        {
                                Queue[++Rear] = elem;
                        }

                }
        }
        int dequeue()
        {
                int elem,i;
                if(Front > Rear)
                {
                        cout<<"Underflow"<<endl;
                }
                else
                {
                        elem = Queue[Front];
                        Front++;

                }
                return elem;
        }



};
int main()
{
        int V;
        //Example (I)
        int data[LEN][LEN] =  {
                                        {0,1,1,1,0,0,0,0,0},
                                        {0,0,0,0,1,0,0,0,0},
                                        {0,1,0,0,0,0,1,0,0},
                                        {0,0,1,0,0,0,1,0,0},
                                        {0,0,1,0,0,1,0,0,0},
                                        {0,0,1,0,0,0,0,1,0},
                                        {0,0,0,0,0,1,0,1,1},
                                        {0,0,0,0,1,0,0,0,1},
                                        {0,0,0,0,0,1,0,0,0}
        };
                cout<<"Enter number of Vertices = ";
                cin>>V;

        BFS ob(data,V);
        ob.process();



        getche();
        return 0;
}
