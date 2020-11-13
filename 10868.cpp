#include <cstdio>
#include <algorithm>
#include <limits>

int a[100000];
int d[300000];

void init(int node, int start, int end){
	if(start == end){
		d[node] = a[start];
	}else{
		init(node * 2, start, (start + end) / 2);
		init(node * 2 + 1, (start + end) / 2 + 1, end);
		d[node] = std::min(d[node * 2], d[node * 2 + 1]);
	}
}

int go(int node, int start, int end, int i, int j){
	if(j < start || i > end){
		return std::numeric_limits<int>::max();
	}
	if(i <= start && j >= end){
		return d[node];
	}
	return std::min(go(node * 2, start, (start + end) / 2, i, j), go(node * 2 + 1, (start + end) / 2 + 1, end, i, j));
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	init(1, 0, n-1);
	for(int j = 0; j < m; ++j){
		int start, end;
		scanf("%d %d", &start, &end);
		printf("%d\n", go(1, 0, n-1, start-1, end-1));
	}
	return 0;
}
