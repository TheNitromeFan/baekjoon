#include <cstdio>

int main(){
    char eevee[3][10] = {"Vaporeon", "Jolteon", "Flareon"};
    int n;
    scanf("%d", &n);
    printf("%s", eevee[++n%3]);
    return 0;
}
