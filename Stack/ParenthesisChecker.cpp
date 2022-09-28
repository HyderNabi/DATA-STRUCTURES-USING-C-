#include<iostream>
#include<conio.h>
#define LEN 50
//using namespace std;
class stack
{
    public:
    char arr[LEN];
    int top;
    stack()
    {
        top = -1;
    }
    void push(char a)
    {
        if(top == LEN-1)
        {
            cout<<"OverFlow"<<endl;
        }
        else
        {
            top++;
            arr[top] = a;
        }
     }

     char pop()
     {
         if(top == -1)
         {
             return 0;
         }
         else
         {
             char elem = arr[top];
             top--;
             return elem;
         }
     } 
};
class ParenChecker
{
    char ex[30];
    public:
    void getExp()
    {
        cout<<"Enter an Expression"<<endl;
        cin>>ex;
        cout<<ex<<endl;
    }
    
    
    void Check(stack &op)
    {
        int i=0;
        char c;
        while(ex[i])
        {
            if(ex[i] == '(')
            {
                op.push(ex[i]);
            }
            else if(ex[i] == ')')
            {
                c = op.pop();
                if(c == 0)
                {
                    break;
                }
            }
            
            i++;
        }
        if(op.top == -1 && ex[i] == '\0')
        {
           cout<<"Rightly Parenthesized"<<endl;
        }
        else
        {
            cout<<"Wrongly Parenthesized"<<endl;
        }
    }
};
int main()
{
    stack op;
    ParenChecker ob;
    ob.getExp();
    ob.Check(op);
    getche();
    return 0;
}