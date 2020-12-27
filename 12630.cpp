#include <cstdio>
#include <algorithm>
#define MAX 50

using namespace std;

int swaps(char a[][MAX], int n){
	int ret = 0;
	int b[MAX];
	for(int i = 0; i < n; ++i){
		b[i] = -1;
		for(int j = 0; j < n; ++j){
			if(a[i][j] == '1'){
				b[i] = j;
			}
		}
	}
	for(int i = 0; i < n; ++i){
		int pos = -1;
		for(int j = i; j < n; ++j){
			if(b[j] <= i){
				pos = j;
				break;
			}
		}
		for(int j = pos; j > i; --j){
			swap(b[j], b[j - 1]);
			++ret;
		}
	}
	return ret;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 1; a0 <= t; ++a0){
		int n;
		scanf("%d", &n);
		char a[MAX][MAX];
		for(int i = 0; i < n; ++i){
			scanf("%s", a[i]);
		}
		printf("Case #%d: %d\n", a0, swaps(a, n));
	}
	return 0;
}
