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
	int x = 0, y = 0;
	for(int i = 0; i < MAX; ++i){
		if(a[i] > b[i]){
			++x;
		}else if(a[i] < b[i]){
			++y;
		}
	}
	if(x > y){
		printf("A");
	}else if(x < y){
		printf("B");
	}else{
		printf("D");
	}
	return 0;
}
