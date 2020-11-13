#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> a, b;
	a.resize(n);
	int i;
	for(i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	sort(a.begin(), a.end());
	b.resize(m);
	int j;
	for(j = 0; j < m; ++j){
		scanf("%d", &b[j]);
	}
	sort(b.begin(), b.end());
	i = 0;
	j = 0;
	int cnt = 0;
	while(i < n && j < m){
		if(a[i] < b[j]){
			++cnt;
			++i;
		}else if(a[i] > b[j]){
			++j;
		}else{
			a[i] = 0;
			++i;
			++j;
		}
	}
	while(i < n){
		++cnt;
		++i;
	}
	printf("%d\n", cnt);
	for(i = 0; i < n; ++i){
		if(a[i] > 0){
			printf("%d ", a[i]);
		}
	}
	return 0;
}
