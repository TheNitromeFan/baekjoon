#include <cstdio>
#include <algorithm>

using std::sort;

void print_sequence(int a[10], int b[10], int n, int m, int pos){
	if(m == pos){
		for(int i = 0; i < m; ++i){
			printf("%d ", b[i]);
		}
		printf("\n");
		return;
	}
	for(int j = 0; j < n; ++j){
		b[pos] = a[j];
		print_sequence(a, b, n, m, pos + 1);
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	bool num[10001] = {};
	int a[10] = {};
	int idx = 0;
	for(int i = 0; i < n; ++i){
		int x;
		scanf("%d", &x);
		if(!num[x]){
			a[idx] = x;
			++idx;
		}
		num[x] = true;
	}
	sort(a, a + idx);
	int b[10] = {};
	print_sequence(a, b, idx, m, 0);
	return 0;
}
