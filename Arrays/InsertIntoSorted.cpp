#include<iostream>
#include<conio.h>
#define LEN 20
using namespace std;
class Arr
{
        int List[LEN];
        int UP;
public:
        Arr()
        {
                UP = 0;
        }
        void insert(int elem)
        {
                if(UP == 0)
                {
                        List[UP] = elem;
                        UP++;
                }
                else
                {
                       for(int i = UP;i>=0;i--)
                        {
                                if(elem<List[i-1] && i!=0)
                                {
                                      List[i] = List[i-1];
                                }
                                else
                                {
                                        List[i] = elem;
                                        UP++;
                                        break;
                                }
                        }

                }


        }
        void print()
        {
                for(int i =0; i<UP;i++)
                {
                        cout<<List[i]<<"\t";
                }
                cout<<endl;
        }
};
int main()
{
        int elem;
        Arr array;
        while(true)
        {
                cout<<"Enter the element = ";
                cin>>elem;
                if(elem == -1)
                {
                        break;
                }
                array.insert(elem);
                array.print();

        }



        getche();
        return 0;
}
