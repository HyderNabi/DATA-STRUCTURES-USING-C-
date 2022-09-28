#include<iostream>
#include<conio.h>
#define LEN 20
#define C1 1
#define C2 3
using namespace std;
class Hash
{
        int Hash_Table[LEN];
        int m; //length of Hash Table
public:
        Hash(int length)
        {
                m = length;
                for(int i=0;i<m;i++)
                {
                        Hash_Table[i] = -1;  //initial sentinel values
                }
        }
        void insertData()
        {
                int key,index;
                int i;
                while(true)
                {
                        cout<<"Enter Element = ";
                        cin>>key;
                        if(key == -1)
                                break; //exit condition

                        i = 0;
                        while (true)
                        {
                                index = (H(key) + (C1 * i) +(C2 * i*i))  % m;
                                // i = probe value :::: i  = 0,1,2,.....,m
                                // m= size of Hash Table

                                if(Hash_Table[index] == -1)
                                {
                                        Hash_Table[index] = key;
                                        cout<<key<<" inserted successfully at position "<<index<<endl;
                                        break;
                                }
                                else if(index >= m)
                                {
                                        cout<<"OverFlow"<<endl;
                                        break;
                                }
                                else
                                {
                                        i++;
                                }

                        }
                }
        }//insert ends here

        int H(int x)
        {
                return x % m; //m = size of hash table
        }
        void display()
        {
                cout<<endl;
                cout<<"Display contents of Hash table"<<endl;
                for(int i=0;i<m;i++)
                {
                        cout<<"index = "<<i<<" Value = "<<Hash_Table[i]<<endl;
                }
        }
        void search()
        {
                cout<<endl<<"Search module"<<endl;
                int key,index;
                int i;
                while (true)
                {
                        cout<<"Enter value to search in Hash Table = ";
                        cin>>key;
                        if(key == -1)
                                break;
                        i = 0;
                        while(true)
                        {
                                 index = (H(key) + (C1 * i) +(C2 * i*i))  % m;
                                if(Hash_Table[index] == key)
                                {
                                        cout<<"The value = "<<key<<" is found at position "<<index<<endl;
                                        break;
                                }
                                else if(Hash_Table[index] == -1 || index >= m)
                                {
                                        cout<<"The Value is not present in the Hash Table"<<endl;
                                        break;
                                }
                                else
                                {
                                        i++;
                                }
                        }
                }

        }//search ends here
};
int main()
{
        int length;
        cout<<"Enter the Length of Hash Table = ";
        cin>>length;
         Hash hash(length);
         hash.insertData();
         hash.display();
         hash.search();
        getche();
        return 0;
}
