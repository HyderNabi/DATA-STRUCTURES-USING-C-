#include<iostream>
#include<conio.h>
#include<math.h>
#define LEN 50
using namespace std;
class stack
{
    public:
    int arr[LEN];
    int top;
    stack()
    {
        top = -1;
    }
    void push(int a)
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

     int pop()
     {
         if(top == -1)
         {
             cout<<"UNDERFLOW"<<endl;
             return 0;
         }
         else
         {
             int elem = arr[top];
             top--;
             return elem;
         }
     }  
     int peek()
     {
         if(top == -1)
         {
            cout<<"UNDERFLOW"<<endl;
            return 0;
         }
         else
         {
             return arr[top];
         }
     }  
     
};
class PostfixEval
{
    char ex[30];
    public:
    void getExp()
    {
        cout<<"Enter an postfix Expression"<<endl;
        cin>>ex;
        cout<<ex<<endl;
    }
  
    void Eval(stack &op)
    {
        int oprnd1,oprnd2;
        int i=0;
        while(ex[i])
        {
            
            if(isalnum(ex[i]))
            {
                op.push(ex[i] -'0');
            }
            else
            {
                oprnd1 = op.pop();
                oprnd2 = op.pop();
                if(ex[i] == '^')
                {
                    op.push(pow(oprnd2,oprnd1));
                }
                else if(ex[i] == '*')
                {
                    op.push(oprnd1*oprnd2);
                }
                else if(ex[i] == '/')
                {
                    op.push(oprnd2 / oprnd1);
                }
                else if(ex[i] == '%')
                {
                    op.push(oprnd2 % oprnd1);
                }
                else if(ex[i] == '+')
                {
                    op.push(oprnd1 + oprnd2);
                }
                else if(ex[i] == '-')
                {
                    op.push(oprnd2 - oprnd1);
                }
            }
            
            
            i++;
        }
        cout<<op.pop();
    }
};
int main()
{
    stack op;
    PostfixEval ob;
    ob.getExp();
    ob.Eval(op);
    getche();
    return 0;
}