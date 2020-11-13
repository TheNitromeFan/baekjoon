#include <cstdio>

int main(){
	int test = 0;
	while(true){
		int p, e, i, d;
		scanf("%d %d %d %d", &p, &e, &i, &d);
		if(p == -1 && e == -1 && i == -1 && d == -1){
			break;
		}
		++test;
		for(int day = d + 1; day <= 23 * 28 * 33; ++day){
			if(day % 23 == p % 23 && day % 28 == e % 28 && day % 33 == i % 33){
				printf("Case %d: the next triple peak occurs in %d days.\n", test, day - d);
				break;
			}
		}
		
	}
	return 0;
}
