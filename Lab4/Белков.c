#include <stdio.h>
double polynom(const char *expr, double x){
    double v=0;
    double a;
    int st, mn, c, p, piocl;
    int io=0;
    int pio=0;
    char o='+';
    char po='+';
    for(int i = 0; expr[i]!=0; i++){
        if((expr[i]=='+') || (expr[i]=='-')){
            pio=io;
            po=o;
            io=i+1;
            o=expr[i];
            p = 1;
            piocl=pio;
            for(piocl; piocl!=(io-1); piocl++){
                if(expr[piocl]=='x') p=0;
            }
            if(p==1){
                a=0.0;
                c=0;
                for(pio; pio!=(io-1); pio++){
                    c=expr[pio]-'0';
                    a = a*10 + c;
                }
                if(po=='-') v-=a;
                else v+=a;
            }
        }
        if(expr[i]=='x'){
            a = x;
            if(expr[i+1]=='^'){
                st = expr[i+2]-'0';
                for(st; st!=1; st--) a = a * x;
            }
            if((i!=0) && ((expr[i-1]=='*') || (io==i))){
                if(io==i){
                    if(o=='-') a = a * (-1);
                }
                else{
                    mn=0;
                    c=0;
                    for(io; expr[io]!='*';io++){
                        c=expr[io]-'0';
                        mn = mn*10 + c;
                    }
                    a = a * mn;
                    if(o=='-') a = a * (-1);
                }
            }
            v+=a;
        }
    }
    c=0;
    a=0;
    for(io; expr[io]!=0; io++){
        c=expr[io]-'0';
        a = a*10 + c;
    }
    if(o=='-') v-=a;
    else v+=a;
    return v;
}
int main()
{
    const char *expr = "x^4+15*x^3-3*x^2+x-2";
    double x = -10.5;
    printf("%f", polynom(expr, x));
}
