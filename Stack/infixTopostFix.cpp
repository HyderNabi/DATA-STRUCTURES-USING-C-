#include<iostream>
#include<conio.h>
#define LEN 50
using namespace std;
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
             cout<<"UNDERFLOW"<<endl;
             return 0;
         }
         else
         {
             char elem = arr[top];
             top--;
             return elem;
         }
     }  
     char peek()
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
     void display()
     {
         if(top == -1)
         {
             cout<<"List is Empty"<<endl;
         }
         else
         {
             for(int i = top; i >= 0; i--)
             {
                 cout<<arr[i]<<endl;
             }
         }
     }
};
class inToPo
{
    char ex[30];
    public:
    void getExp()
    {
        cout<<"Enter an infix Expression"<<endl;
        cin>>ex;
        //cout<<ex<<endl;
    }
    int Precedence(char optr)
    {
        
        if(optr == '^')
        {
            return 3;
        }
        else if(optr == '*' || optr == '/' || optr == '%')
        {
            return 2;
        }
        else if(optr == '+' || optr =='-')
        {
            return 1;
        }

    }
    char Associativity(char optr)
    {
        if(optr == '*' || optr == '/' || optr == '%')
        {
            return 'L';
        }
        else if(optr == '+' || optr =='-')
        {
            return 'L';
        }
    }
    void Convert(stack &op)
    {
        int i=0;
        while(ex[i])
        {
            
            if(isalpha(ex[i]) || isalnum(ex[i]))
            {
                cout<<ex[i];
            }
            else if(op.top == -1 || op.peek() == '(')
            {
                op.push(ex[i]);
            }
            else if(ex[i] == '(')
            {
                op.push(ex[i]);
            }
            else if(ex[i] == ')')
            {
                while(op.peek() != '(' && op.top != -1)
                {
                    cout<<op.pop();
                }
                op.pop();
            }
            else if(Precedence(ex[i]) > Precedence(op.peek()))
            {
                op.push(ex[i]);
            }
            else if(Precedence(ex[i]) < Precedence(op.peek()))
            {
                    cout<<op.pop();
                    continue;
            }
            else if(Precedence(ex[i]) == Precedence(op.peek()))
            {
                if(Associativity(ex[i]) == 'L')
                {
                    cout<<op.pop();
                    op.push(ex[i]);
                }
                else if(Associativity(ex[i]) == 'R')
                {
                    op.push(ex[i]);
                }
            } 
            else if(ex[i] == op.peek())
            {
                op.push(ex[i]);
            }
            i++;
        }
        if(ex[i] == '\0')
        {
            while(op.top != -1)
            {
                cout<<op.pop();
            }

        }
    }
};
int main()
{
    stack op;
    inToPo ob;
    ob.getExp();
    ob.Convert(op);
    getche();
    return 0;
}