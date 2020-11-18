#include <cstdio>
#include <utility>
#define MOD 1000000007

using namespace std;

pair<long long, long long> inv(long long a, long long b){
	if(b == 0){
		return make_pair(1, 0);
	}else{
		pair<long long, long long> p = inv(b, a % b);
		long long x = p.second;
		long long y = p.first - a / b * x;
		return make_pair(x, y);
	}
}

int main(){
	int n, r;
	scanf("%d %d", &n, &r);
	static long long fact[1000001] = {};
	fact[0] = 1;
	for(int i = 1; i <= n; ++i){
		fact[i] = fact[i - 1] * i;
		fact[i] %= MOD;
	}
	pair<long long, long long> p1 = inv(fact[r], MOD), p2 = inv(fact[n - r], MOD);
	long long ans = fact[n];
	while(p1.first < 0){
		p1.first += MOD;
	}
	ans *= p1.first;
	ans %= MOD;
	while(p2.first < 0){
		p2.first += MOD;
	}
	ans *= p2.first;
	ans %= MOD;
	printf("%lld", ans);
	return 0;
}
