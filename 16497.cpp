#include <cstdio>
#define MAX 101

bool checkout(int out[MAX], int in[MAX], int k){
	for(int i = 0; i < MAX; ++i){
		k += in[i] - out[i];
		if(k < 0){
			return false;
		}
	}
	return true;
}

int main(){
	int n;
	scanf("%d", &n);
	int out[MAX] = {}, in[MAX] = {};
	for(int i = 0; i < n; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		++out[a];
		++in[b];
	}
	int k;
	scanf("%d", &k);
	printf("%d", checkout(out, in, k));
	return 0;
}
