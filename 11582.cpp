#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> psort(vector<int> &v, int n, int k){
	int len = n / k;
	for(int i = 0; i < n; i += len){
		sort(v.begin() + i, v.begin() + i + len);
	}
	return v;
}

int main(){
	int n;
	scanf("%d", &n);
	vector<int> v(n, 0);
	for(int i = 0; i < n; ++i){
		scanf("%d", &v[i]);
	}
	int k;
	scanf("%d", &k);
	psort(v, n, k);
	for(int i = 0; i < n; ++i){
		printf("%d ", v[i]);
	}
	return 0;
}
