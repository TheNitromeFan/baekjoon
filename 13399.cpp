#include <cstdio>
#include <algorithm>

using std::sort;

int last[200001];

bool key(int i, int j){
	return last[i] > last[j] || (last[i] == last[j] && i < j);
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; ++i){
		int e;
		scanf("%d", &e);
		last[e] = i;
	}
	int line[200001];
	for(int x = 1; x <= n; ++x){
		line[x] = x;
	}
	sort(line + 1, line + n + 1, key);
	for(int x = 1; x <= n; ++x){
		printf("%d\n", line[x]);
	}
	return 0;
}
