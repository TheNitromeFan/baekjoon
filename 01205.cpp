#include <cstdio>
#define MAX (50 + 1)

int place(int a[MAX], int n, int score, int p){
	for(int i = 1; i <= n; ++i){
		if(a[i] < score){
			return i;
		}else if(a[i] == score){
			if(n == p && a[p] == score){
				return -1;
			}else{
				return i;
			}
		}
	}
	if(n < p){
		return n + 1;
	}
	return -1;
}

int main(){
	int n, score, p;
	scanf("%d %d %d", &n, &score, &p);
	int a[MAX];
	for(int i = 1; i <= n; ++i){
		scanf("%d", &a[i]);
	}
	printf("%d", place(a, n, score, p));
	return 0;
}
