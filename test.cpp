#include<bits/stdc++.h>

int main()
{
    using namespace std;
    int a = 6164, b = 25532;
    int sx = 0, sy = 0;
    printf("%d %d\n", (a+1)/2+b, a+b);
    for(int i=0 ; i<a/2; i++)
    {
        sx+=2, sy+=2;
        printf("%d %d\n", sx, sy);
    }
    if(a%2)
    {
        sx+=1, sy+=1;
        printf("%d %d\n", sx, sy);
    }
    for(int i=0; i<b; i++)
    {
        sx+=2, sy+=1;
        printf("%d %d\n", sx , sy);
    }
    return 0;
}

