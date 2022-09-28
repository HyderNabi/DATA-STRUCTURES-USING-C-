#include<iostream>
#include<conio.h>
#define LEN 20
using namespace std;
class Prim
{
        int AdjMat[LEN][LEN];
        int V;
        int SpanningTree[LEN][LEN];
        int LabelT[LEN];
        int LabelF[LEN];
public:
        Prim(int data[LEN][LEN],int V)
        {
                int i,j;
                this->V = V;
                for(i = 0;i<V;i++)
                {
                        LabelT[i] = 0;
                        LabelF[i] = 0;
                        for(j = 0;j<V;j++)
                        {
                                AdjMat[i][j] = data[i][j];
                                SpanningTree[i][j] = 0;
                        }
                }
        }
        void Procedure_Prim(int initial)
        {
                int Tree[LEN];  //Tree Vertices
                int Fringe[LEN]; //Fringe Vertices

                int selected;
                int j;
                int tn,fn;
                tn = 0; //size of Tree
                fn = 0; //size of Fringe

                Tree[tn] = initial;
                LabelT[initial] = 1;
                selected = Tree[tn];
                tn++;

                do
                {

                         for(j=0;j<V;j++)
                        {

                                if(AdjMat[selected][j] != 0 && LabelT[j]==0 && LabelF[j] ==0)
                                {
                                        Fringe[fn] = j;
                                        LabelF[j] = 1;
                                        fn++;
                                        cout<<"ho";
                                }
                        }



                        selected = Min(Tree,Fringe,tn,fn);
                        Tree[tn] = selected;
                        LabelT[selected] = 1;
                        tn++;
                        Remove(Fringe,selected,&fn);


              }while(fn>0);
        }

        int Min(int Tree[LEN] ,int Fringe[LEN],int tn,int fn)
        {
        	   int small ;
                int temp,i,j,a,b;
                disp(Tree,tn);
                disp(Fringe,fn);



              small  = 1000;

                cout<<"small "<<small<<endl;

                for(i=0;i<tn;i++)
                {
                        for(j=0;j<fn;j++)
                        {

                                temp = AdjMat[Tree[i]][Fringe[j]];

                                if( (temp != 0 && temp<small))
                                {

                                       small = temp;
                                       a = Tree[i];
                                       b = Fringe[j];



                                }
                        }
                }
                //Add the lowest cost edge to spanning tree;
                cout<<small<<endl;
                cout<<b<<endl;

                SpanningTree[a][b] = AdjMat[a][b];
                SpanningTree[b][a] = AdjMat[b][a];


                return b;
        }

        void Remove(int *ptr,int selected,int *fn)
        {

                int i,j;
                int index;
                for(i=0;i<*fn;i++)
                {

                        if(*(ptr+i) == selected)
                        {

                                index = i;
                                break;
                        }
                }
                if(index == (*fn)-1)
                {
                 	*fn = (*fn)-1;
                }
                else
                {
                	for(i = index;i<(*fn)-1;i++)
                  {
                  			*(ptr+i) = *(ptr+i+1);

                  }
                  *fn = (*fn)-1;
                }

        }
        void display()
        {
                int i,j;
                for(i = 0;i<V;i++)
                {
                        for(j = 0;j<V;j++)
                        {
                                cout<<SpanningTree[i][j]<<"\t";
                        }
                        cout<<endl;
                }

        }
        void disp(int arr[],int l)
        {
        int i;
        for(i=0;i<l;i++)
        {
        cout<<arr[i]<<" " ;
        }
        cout<<endl;
        }


};
int main()
{
        int V;
        int n;
  /*     int data[LEN][LEN] ={
                                                        {0,7,3,0,0},
                                                        {7,0,4,9,11},
                                                        {3,4,0,10,0},
                                                        {0,9,10,0,0},
                                                        {0,11,0,0,0}
        };

        int data[LEN][LEN] ={
                                                        {0,6,0,4,0,0,0},
                                                        {6,0,7,8,6,0,0},
                                                        {0,7,0,0,4,0,0},
                                                        {4,8,0,0,14,5,0},
                                                        {0,6,4,14,0,7,8},
                                                        {0,0,0,5,7,0,10},
                                                        {0,0,0,0,8,10,0},
        };

       int data[LEN][LEN] ={
                                                        {0,6,1,5,0,0},
                                                        {6,0,5,0,3,0},
                                                        {1,5,0,5,6,4},
                                                        {5,0,5,0,0,2},
                                                        {0,3,6,0,0,6},
                                                        {0,0,4,2,6,0}
        };  */

         int data[LEN][LEN] ={
                                                        {0,5,5,0,0,0},
                                                        {5,0,1,0,0,0},
                                                        {5,1,0,3,1,5},
                                                        {0,0,3,0,0,3},
                                                        {0,0,1,0,0,3},
                                                        {0,0,5,3,3,0}
        };






        cout<<"Enter the number of Vertices = ";
        cin>>V;
        cout<<"Enter the Starting Vertex = ";
        cin>>n;
        Prim prim(data,V);
        prim.Procedure_Prim(n);
        prim.display();
        getche();
        return 0;
}
