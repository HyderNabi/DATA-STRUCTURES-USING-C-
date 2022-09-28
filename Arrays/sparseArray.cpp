#include<iostream>
#include<conio>
int main()
{
    int i,j,size=0;

    int arr[5][5] = { {0,0,0,1,0},
    						 {0,0,5,0,0},
                      {0,6,0,0,0},
                      {0,0,0,0,9},
                      {4,0,0,0,0},
                    };
    for(i=0;i<5;i++)
    {
    	for(j=0;j<5;j++)
      {
      	if(arr[i][j] != 0)
         {
         	size++;
         }
      }
    }
 int matrix[3][10];
 int k = 1;
 matrix[0][0] = 5;
 matrix[1][0] = 5;
 matrix[2][0] = size;


     for(i=0;i<5;i++)
    {
    	for(j=0;j<5;j++)
      {
      	if(arr[i][j] != 0)
         {
         	matrix[0][k] = i;
            matrix[1][k] = j;
            matrix[2][k] = arr[i][j];
            k++;
         }

      }
    }

 for(i=0;i<3;i++)
    {
    	for(j=0;j<size;j++)
      {
      	cout<< matrix[i][j]<<"\t";
      }
      cout<<endl;
    }

    getche();
    return 0;
}