#include <stdio.h>
#include <math.h>
float traverse_clockwise(float coord[], int n)
{
    int n1=1;
    int bx=0;
    float v=0;
    int x1=0;
    int y1=1;
    int x2, y2;
    int a, b;
    while(n1<n)
    {
        for(int i = 0; i < (n*2); i+=2)
        {
            if((coord[x1]==coord[i]) && (coord[y1]==coord[i+1]) && (i!=bx)) continue;
            x2=i; y2=i+1;
            a = 0;
            for(int j = 0; j < (n*2); j+=2)
            {
                if((coord[j]-coord[x1])*(coord[y2]-coord[y1])>(coord[j+1]-coord[y1])*(coord[x2]-coord[x1])) a++;
            }
            if((a==(n-2)))
            {
                a=((coord[x2]-coord[x1])*(coord[x2]-coord[x1])) + ((coord[y2]-coord[y1])*(coord[y2]-coord[y1]));
                v+=(sqrt(a));
                bx=x1;
                x1=x2;
                y1=y2;
                n1++; //<-- Здесь проблемма
            }
        }

    }
    return v;
}
int main()
{
    float rect[] = {1,5,7,1,7,5,1,1};
    float star[] = {3.97, 0.82, 2.26, 3.69, 5.39, 2.16, 2.03, 2.11, 5.36, 4.06};
    float enneagon[] ={ 76, 67.1, -8.3, 18, 55, 93.3, 77, 33, 21.3, 99, -20, 50, -8.3, 82, 55, 6.7,  21.3, 0.76};
    printf("%f", traverse_clockwise(rect, (sizeof(enneagon)/sizeof(enneagon[0]))/2));
}
