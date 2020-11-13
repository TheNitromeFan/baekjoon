#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

vector<pair<long long, long long>> v;

void prime_powers(long long n){
	long long cnt = 0;
	while(n % 2 == 0){
		n /= 2;
		++cnt;
	}
	if(cnt > 0){
		v.push_back({2, cnt});
	}
	for(long long p = 3; p*p <= n; p += 2){
		cnt = 0;
		while(n % p == 0){
			n /= p;
			++cnt;
		}
		if(cnt > 0){
			v.push_back({p, cnt});
		}
	}
	if(n > 1){
		v.push_back({n, 1});
	}
}

long long legendre(long long n, long long p){
	long long ans = 0;
	while(n >= p){
		ans += n/p;
		n /= p;
	}
	return ans;
}

int main(){
	int t;
	scanf("%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		v.clear();
		long long n, k;
		scanf("%lld %lld", &n, &k);
		prime_powers(k);
		long long mn = 1000000000000000000LL;
		for(pair<long long, long long> p : v){
			long long tmp = legendre(n, p.first) / p.second;
			if(tmp < mn){
				mn = tmp;
			}
		}
		printf("%lld\n", mn);
	}
	return 0;
}
