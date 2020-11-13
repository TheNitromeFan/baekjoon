#include <cstdio>

int cycles(int *arr, int n){
	int answer = 0;
	int visited[1001] = {};
	for(int i = 1; i <= n; ++i){
		if(!visited[i]){
			++answer;
			visited[i] = true;
			int j = i;
			do{
				j = arr[j];
				visited[j] = true;
			}while(j != i);
		}
	}
	return answer;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a = 0; a < t; ++a){
		int p[1001];
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i){
			scanf("%d", &p[i]);
		}
		printf("%d\n", cycles(p, n));
	}
	return 0;
}
