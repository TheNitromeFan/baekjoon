#include <cstdio>
#include <vector>

using std::vector;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> a(n, 0), b(m, 0), c(n + m, 0);
	int i, j;
	for(i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	for(j = 0; j < m; ++j){
		scanf("%d", &b[j]);
	}
	i = 0;
	j = 0;
	while(i + j < n + m){
		if(i == n){
			c[i + j] = b[j];
			++j;
		}else if(j == m){
			c[i + j] = a[i];
			++i;
		}else if(a[i] < b[j]){
			c[i + j] = a[i];
			++i;
		}else{
			c[i + j] = b[j];
			++j;
		}
	}
	for(int k = 0; k < n + m; ++k){
		printf("%d ", c[k]);
	}
	return 0;
}
