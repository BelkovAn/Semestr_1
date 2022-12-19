#include <stdio.h>
int Calc(char *exp)
{
    char io, ie, ix; // index of operator, equel, x
    int a = -1, b = -1; // first and second operand, x
    if((exp[0]-'0'>=0) && (exp[0]-'0'<=9)) a=exp[0]-'0';// Определение где х и какие числа
    else ix = 0;
    if((exp[2]-'0'>=0) && (exp[2]-'2'<=9)){
        if(a==-1) a=exp[2]-'0';
        else b=exp[2]-'0';
    }
    else ix = 2;
    if((a!=-1) && (b!=-1)) ix=4;
    else b=exp[4]-'0';
    if(exp[1]=='=') // Определение где знак и равно
    {
        ie=1;
        io=3;
    }
    else{
        ie=3;
        io=1;
    }
    if((ix==0 && ie==1) || (ie==3 && ix==4)){ // если х за знаком равно
        switch(exp[io])
        {
            case '+' : return a+b; break;
            case '-' : return a-b; break;
            case '*' : return a*b; break;
            case '/' : return a/b; break;
            case '%' : return a%b; break;
        }
    }
    else if(ie==1) // если а за знаком равно
    {
        if(exp[io]=='+') return a-b;
        else if(exp[io]=='*') return a/b;
        else if(exp[io]=='-')
        {
            if(ix==4) return b-a;
            else return a+b;
        }
        else if(exp[io]=='/')
        {
            if(ix==4) return b/a;
            else return a*b;
        }
    }
    else if(ie==3) // если b за знаком равно
    {
        if(exp[io]=='+') return b-a;
        else if(exp[io]=='*') return b/a;
        else if(exp[io]=='-')
        {
            if(ix==2) return a-b;
            else return a+b;
        }
        else if(exp[io]=='/')
        {
            if(ix==2) return a/b;
            else return a*b;
        }
    }
//    return ie;
}

int main()
{
    char *expression[] = {"2+x=5", "x+2=5", "2+x=5", "x-5=2", "5-x=2", "x=5*2", "9*9=x", "x/2=5"};
    int len = sizeof (expression) / sizeof (char *);
    for(int i=0; i<len; i++)
    {
        printf("%s x=%d\n", expression[i], Calc(expression[i]));
    }
    return 0;
}
