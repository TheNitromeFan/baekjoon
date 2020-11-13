#include <cstdio>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

bool cmp(tuple<long long, int, int> a, tuple<long long, int, int> b){
	return get<2>(a) > get<2>(b) || (get<2>(a) == get<2>(b) && get<1>(a) < get<1>(b));
}

int power(long long x, int p){
	int ret = 0;
	while(x % p == 0){
		x /= p;
		++ret;
	}
	return ret;
}

int main(){
	int n;
	scanf("%d", &n);
	vector<tuple<long long, int, int>> v(n);
	for(int i = 0; i < n; ++i){
		long long x;
		scanf("%lld", &x);
		int p2 = power(x, 2), p3 = power(x, 3);
		v[i] = make_tuple(x, p2, p3);
	}
	sort(v.begin(), v.end(), cmp);
	for(tuple<long long, int, int> t : v){
		printf("%lld ", get<0>(t));
	}
	return 0;
}
