#include <cstdio>

int main(){
	int n;
	scanf("%d", &n);
	int maxA = -1, minB = 1001;
	for(int i = 0; i < n; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		if(maxA < a){
			maxA = a;
		}
		if(minB > b){
			minB = b;
		}
	}
	if(maxA <= minB){
		printf("gunilla has a point");
	}else{
		printf("edward is right");
	}
	return 0;
}
