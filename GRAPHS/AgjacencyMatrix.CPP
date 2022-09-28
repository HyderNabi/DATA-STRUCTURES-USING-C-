#include<iostream>
#include<conio.h>
#define ROWS 50
#define DIMEN 10
using namespace std;
class AdjMat
{
        int edges[ROWS][2];
        int adjacent_matrix[DIMEN][DIMEN] = {0};
        int V,E;
public:
        void createMat()
        {
                int i,j,a,b;
                cout<<"No. of Vertices =  "<<endl;
                cin>>V;
                cout<<"No. of Edges =  "<<endl;
                cin>>E;
                cout<<"Enter the end points of "<<E<<" edges(Values less than the "<<V<<" )"<<endl;
                for( i = 1;i<=E;i++)
                {
                        for( j = 1;j<=2;j++)
                        {
                                cin>>edges[i][j];
                        }
                }

                for(i = 1;i<=E;i++)
                {
                        a = edges[i][1];
                        b = edges[i][2];

                        adjacent_matrix[a][b] = 1;
                        adjacent_matrix[b][a] = 1;

                }
        }

        void displayMat()
        {
                int i ,j;
                cout<<endl<<"ENTERED EDGES"<<endl;
                cout<<"[";
                for(i=1;i<=E;i++)
                {
                        cout<<"(";
                        for(j=1;j<=2;j++)
                        {
                                if(j==2)
                                        cout<<" ";
                                cout<<edges[i][j];
                        }
                        cout<<")";
                }
                cout<<"]"<<endl;
                cout<<endl<<"ADJACENCY MATRIX OF ABOVE EDGES IS:"<<endl;
                cout<<"\t";
                for(i=1;i<=V;i++)
                        cout<<i<<"\t";
                cout<<endl<<"-----------------------------------------"<<endl;
                cout<<endl;
                for( i = 1;i<=V;i++)
                {
                        cout<<i<<"|"<<"\t";
                        for( j = 1;j<=V;j++)
                        {
                                cout<<adjacent_matrix[i][j]<<"\t";
                        }
                        cout<<endl;
                }

        }
};
int main()
{
   AdjMat obj;
   obj.createMat();
   obj.displayMat();
}
