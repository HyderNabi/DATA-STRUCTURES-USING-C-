#include<iostream>
#include<conio.h>
#define LEN  20
using namespace std;
class BellMan{
        int AdjMat[LEN][LEN];
        int D[LEN] ;   //using 10000 as INFINITE
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
                }

        }
        void BellManFord()
        {
                int r,i,j;
                int distance_u,distance_v,cost_u_v,sum;
                //Distance/Cost of initial Vertex = 0
                D[0] = 0;
                //no of Relaxations = V-1
                for(r = 1;r<V;r++)
                {
                        for(i=0;i<V;i++)
                        {
                                for(j=0;j<V;j++)
                                {
                                        if(AdjMat[i][j] !=  0)
                                        {
                                                //To-Do:  bell man ford cost calculation
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
                        }//     i ends here

                } //r ends here
        }

        void display()
        {
                int i,j;
                for(i = 0;i<V;i++)
                {
                        cout<<"Distance of Node "<<i<< " from initial Node 1 = "<<D[i]<<endl;
                }

        }

};
int main()
{
        //Example (I)
    /*    int data[LEN][LEN] =  {
                                        {0,6,5,5,0,0,0},
                                        {0,0,0,0,-1,0,0},
                                        {0,-2,0,0,1,0,0},
                                        {0,0,-2,0,0,-1,0},
                                        {0,0,0,0,0,0,3},
                                        {0,0,0,0,0,0,3},
                                        {0,0,0,0,0,0,0}

                          };   */
        //Example (II)
       int data[LEN][LEN] = {
                {0,4,0,5},
                {0,0,0,0},
                {0,-10,0,0},
                {0,0,3,0}
        };

        //Example (III):::::::::::Negative Cycle
     /*   int data[LEN][LEN] = {
                {0,4,0,5},
                {0,0,0,4},
                {0,-10,0,0},
                {0,0,3,0}
        };   */

        BellMan bellMan;
        bellMan.getData(data);
        bellMan.BellManFord();
        bellMan.display();
        getche();
        return 0;
}
