#include <cstdio>
#define MAX 10

int main(){
	int a[MAX], b[MAX];
	for(int i = 0; i < MAX; ++i){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < MAX; ++i){
		scanf("%d", &b[i]);
	}
	int p1 = 0, p2 = 0, last = 0;
	for(int i = 0; i < MAX; ++i){
		if(a[i] > b[i]){
			p1 += 3;
			last = 1;
		}else if(a[i] < b[i]){
			p2 += 3;
			last = 2;
		}else{
			p1 += 1;
			p2 += 1;
		}
	}
	printf("%d %d\n", p1, p2);
	if(p1 > p2 || (p1 == p2 && last == 1)){
		printf("A");
	}else if(p1 < p2 || (p1 == p2 && last == 2)){
		printf("B");
	}else{
		printf("D");
	}
	return 0;
}
