#include<iostream>
#include<conio.h>
#define LEN 20
#define INF 10000
using namespace std;
class Floyd_Warshal
{
        int  DistanceMatrix[LEN][LEN];
        int V;
public:
        void getData(int data[LEN][LEN])
        {
                cout<<"Enter the number of Vertices"<<endl;
                cin>>V;
                int i,j;
                for(i=0;i<V;i++)
                {
                        for(j=0;j<V;j++)
                        {
                                if(data[i][j] == 0 && i!=j)
                                        DistanceMatrix[i][j] = INF;
                                else
                                        DistanceMatrix[i][j] = data[i][j];
                        }
                }
        }
        //Floyd's - Warshalls Procedure
        void FloydWarshal()
        {
                int i,j,k;
                int value_one,value_two;
                int Prev[LEN][LEN];
                _copy(Prev);
                        for(k=0;k<V;k++)
                        {
                                for(i=0;i<V;i++)
                                {
                                        for(j=0;j<V;j++)
                                        {
                                                if(i!=j && i!=k &&j!=k)
                                                {
                                                        value_one = Prev[i][j];
                                                        value_two = Prev[i][k]+Prev[k][j];
                                                        //Find Minimum between the Two
                                                        if(value_one <= value_two)
                                                        {
                                                                DistanceMatrix[i][j] = value_one;
                                                        }
                                                        else
                                                        {
                                                                DistanceMatrix[i][j] = value_two;
                                                        }
                                                }
                                        }
                                }
                                _copy(Prev);
                        }



        }

        void _copy(int prev[LEN][LEN])
        {
                int i,j;
                for(i=0;i<V;i++)
                {
                        for(j=0;j<V;j++)
                        {
                                prev[i][j] = DistanceMatrix[i][j];
                        }
                }

        }


        void display()
        {
                int i,j;
                for(i=0;i<V;i++)
                {
                        for(j=0;j<V;j++)
                        {
                                cout<<DistanceMatrix[i][j]<<"\t";
                        }
                cout<<endl;
                }

        }


};
int main()
{
        /*
        //Example I
        int adjacencyMatrix[LEN][LEN] = {
                                                                                        {0,3,0,7},
                                                                                        {8,0,2,0},
                                                                                        {5,0,0,1},
                                                                                        {2,0,0,0}
                                                                           };

         //Example II
         int adjacencyMatrix[LEN][LEN] = {
                                                                                        {0,8,0,1},
                                                                                        {0,0,1,0},
                                                                                        {4,0,0,0},
                                                                                        {0,2,9,0}
                                                                           };
        */
        //Example III
         int adjacencyMatrix[LEN][LEN] = {
                                                                                        {0,3,8,0,-4},
                                                                                        {0,0,0,1,7},
                                                                                        {0,4,0,0,0},
                                                                                        {2,0,-5,0,0},
                                                                                        {0,0,0,6,0},
                                                                           };

        Floyd_Warshal ob;
        ob.getData(adjacencyMatrix);
        ob.FloydWarshal();
        ob.display();
        getche();
        return 0;
}
