#include <cstdio>
#define MAX 150

int cnt(int a[MAX], int start, int end){
	int ret = 0;
	bool visited[MAX] = {};
	visited[start] = true;
	while(true){
		start = a[start];
		++ret;
		if(start == end){
			return ret;
		}else if(visited[start]){
			return -1;
		}
		visited[start] = true;
	}
	return -1;
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int a[MAX];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	printf("%d", cnt(a, 0, k));
	return 0;
}
