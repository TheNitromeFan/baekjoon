#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<int> a(n, 0);
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	sort(a.begin(), a.end());
	int idx = (n - 1) / 2;
	for(int i = 1; i <= n; ++i){
		printf("%d ", a[idx]);
		if(i % 2){
			idx += i;
		}else{
			idx -= i;
		}
	}
	return 0;
}
