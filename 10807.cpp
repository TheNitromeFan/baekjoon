#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<int> v(n, 0);
	for(int i = 0; i < n; ++i){
		scanf("%d", &v[i]);
	}
	int x;
	scanf("%d", &x);
	printf("%d", count(v.begin(), v.end(), x));
	return 0;
}
