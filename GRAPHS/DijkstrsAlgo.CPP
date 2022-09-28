#include<iostream>
#include<conio.h>
#define LEN  20
using namespace std;
class Dijkstra{
        int AdjMat[LEN][LEN];
        int D[LEN] ;   //using 10000 as INFINITE
        int Selected[LEN];
        int Label[LEN];
        int V,E;
public:

        void getData(int data[LEN][LEN])
        {
                cout<<"Enter number of Vertices = ";
                cin>>V;
                cout<<"Enter number of Edges = ";
                cin>>E;

                int i,j;
                //init weighted Adjacency Matrix of the Graph
                for(i = 0;i<V;i++)
                {
                        for(j=0;j<V;j++)
                        {
                                AdjMat[i][j] = data[i][j];
                        }
                }



                //init Distance matrix
                //it will contain Distance of each node from the initial Node
                //initially 10000 is assigned to each node as an INFINITE value
                for(i=0;i<V;i++)
                {
                        D[i] = 10000;
                        Selected[i] = -1;
                        Label[i] = 0;
                }

        }
        void Dijkstras_Func()
        {
                int r,n,i,j;
                int index = 0;
                int distance_u,distance_v,cost_u_v,sum;

                //initial selected node
                cout<<"Enter initial node = ";
                cin>>n;

                //Distance/Cost of initial Vertex = 0
                D[n] = 0;
                Selected[index] = n;
                Label[n] = 1;
                i = n;
                while (true)
                {
                         for(j=0;j<V;j++)
                                {
                                        if(AdjMat[i][j] !=  0 && Label[j] != 1 )
                                        {
                                                //if d(u)+c(u,v) < d(v)
                                                //then d(v) = d(u) +c(u,v)
                                                distance_u = D[i];
                                                cost_u_v = AdjMat[i][j];
                                                distance_v = D[j];
                                                sum = distance_u + cost_u_v;

                                                if(sum < distance_v)
                                                {
                                                        D[j] = sum;
                                                }
                                        }
                        }// j ends here

                        i = minimum(D,Label);
                        if (i == -1)
                        {
                                break;
                        }
                        else
                        {
                               Selected[++index] = i;
                                Label[i] = 1;
                        }

                }

        }

        int minimum(int D[],int Label[])
        {
                int small,pos,i;
                bool flag;
                for(i=0;i<V;i++)
                {
                        if(Label[i] == 0)
                        {
                                small = D[i];
                                flag = false;
                                break;
                        }
                        else
                        {
                                flag = true;
                        }
                }
                if(flag == true)
                {
                        return -1;
                }
                else
                {
                        for(i=0;i<V;i++)
                        {
                                if(Label[i] == 0 && D[i]<=small)
                                {
                                        small = D[i];
                                        pos = i;
                                }
                        }
                        return pos;
                }

        }


        void display()
        {
                int i,j;
                cout<<endl<<"Selected Nodes"<<"\t"<<"Associated Cost from initial Node"<<endl;
                for(i = 0;i<V;i++)
                {
                        cout<<Selected[i]+1<<"\t\t"<<D[Selected[i]]<<endl;
                }

        }

};
int main()
{
        //Example (I)
  /*      int data[LEN][LEN] =  {
                                        {0,2,4,0,0,0},
                                        {0,0,1,7,0,0},
                                        {0,0,0,0,3,0},
                                        {0,0,0,0,0,1},
                                        {0,0,0,2,0,5},
                                        {0,0,0,0,0,0}
                                };
       //Example II
        int data[LEN][LEN] =  {
                                        {0,0,2,0,0,0,0},
                                        {4,0,0,0,0,0,0},
                                        {0,0,0,0,0,0,0},
                                        {0,15,0,0,0,5,23},
                                        {0,17,0,0,0,0,11},
                                        {0,0,9,0,0,0,13},
                                        {0,0,0,0,0,0,0}
                                };
     //Example III
     int data[LEN][LEN] =  {
                                        {0,3,0,7,0},
                                        {0,0,4,2,0},
                                        {0,0,0,5,6},
                                        {0,0,0,0,4},
                                        {0,0,0,0,0}
                                };
*/
        //Example IV
        int data[LEN][LEN] =  {
                                        {0,50,45,10,0,0},
                                        {0,0,10,15,0,0},
                                        {0,0,0,0,30,0},
                                        {0,0,0,0,15,0},
                                        {0,20,35,0,0,0},
                                        {0,0,0,0,3,0}
                                };

        Dijkstra dj;
        dj.getData(data);
        dj.Dijkstras_Func();
        dj.display();
        getche();
        return 0;
}

