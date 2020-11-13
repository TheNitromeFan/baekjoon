#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

long long rev(long long n){
	long long ret = 0;
	while(n){
		ret = ret * 10 + n % 10;
		n /= 10;
	}
	return ret;
}

int main(){
	int n;
	scanf("%d", &n);
	vector<long long> v(n, 0);
	for(int i = 0; i < n; ++i){
		long long x;
		scanf("%lld", &x);
		v[i] = rev(x);
	}
	sort(v.begin(), v.end());
	for(long long x : v){
		printf("%lld\n", x);
	}
	return 0;
}
