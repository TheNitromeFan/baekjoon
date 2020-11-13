#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

bool visited[8];
int to_print[8];
int num[8];

void backtrack(int n, int m, int len){
	if(len == m){
		for(int i = 0; i < m; ++i){
			printf("%d ", to_print[i]);
		}
		printf("\n");
		return;
	}
	for(int i = 0; i < n; ++i){
		if(!visited[i]){
			visited[i] = true;
			to_print[len] = num[i];
			backtrack(n, m, len+1);
			visited[i] = false;
		}
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i){
		scanf("%d", &num[i]);
	}
	sort(num, num+n);
	backtrack(n, m, 0);
	return 0;
}
