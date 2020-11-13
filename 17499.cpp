#include <cstdio>
#define MAX 200000

int main(){
	int n, q;
	scanf("%d %d", &n, &q);
	int a[MAX];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	int idx = 0;
	for(int j = 0; j < q; ++j){
		int t;
		scanf("%d", &t);
		if(t == 1){
			int i, x;
			scanf("%d %d", &i, &x);
			if(idx + i - 1 < n){
				a[idx + i - 1] += x;
			}else{
				a[idx + i - 1 - n] += x;
			}
		}else if(t == 2){
			int s;
			scanf("%d", &s);
			idx -= s;
			if(idx < 0){
				idx += n;
			}
		}else if(t == 3){
			int s;
			scanf("%d", &s);
			idx += s;
			if(idx >= n){
				idx -= n;
			}
		}
	}
	for(int i = 0; i < n; ++i){
		printf("%d ", a[idx]);
		++idx;
		if(idx == n){
			idx = 0;
		}
	}
	return 0;
}
