#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10000000000000001LL

using namespace std;

long long gcd(long long a, long long b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

long long lcm(long long a, long long b){
	long long tmp = a / gcd(a, b);
	if(tmp <= MAX / b){
		return tmp * b;
	}else{
		return MAX;
	}
}

vector<long long> divisors(long long x){
	vector<long long> ret;
	long long i;
	for(i = 1; i * i < x; ++i){
		if(x % i == 0){
			ret.push_back(i);
			ret.push_back(x / i);
		}
	}
	if(i * i == x){
		ret.push_back(i);
	}
	sort(ret.begin(), ret.end());
	return ret;
}

long long solve(vector<long long > &f, int n, long long l, long long h){
	sort(f.begin(), f.end());
	if(f[0] != 1){
		f.insert(f.begin(), 1);
		++n;
	}
	/*
	for(int i = 0; i < n; ++i){
		cout << f[i] << ' ';
	}
	*/
	vector<long long> lcm1(n);
	lcm1[0] = f[0];
	for(int i = 1; i < n; ++i){
		lcm1[i] = lcm(lcm1[i - 1], f[i]);
	}
	vector<long long> gcd1(n);
	gcd1[n - 1] = f[n - 1];
	for(int i = n - 2; i > 0; --i){
		gcd1[i] = gcd(gcd1[i + 1], f[i]);
	}
	for(int i = 0; i + 1 < n; ++i){
		long long low = lcm1[i], high = gcd1[i + 1];
		if(high < l || low > h || !(low <= high && high % low == 0)){
			continue;
		}
		vector<long long> v = divisors(high);
		for(unsigned j = 0; j < v.size(); ++j){
			if(v[j] >= max(low, l) && v[j] <= min(high, h) && v[j] % low == 0){
				return v[j];
			}
		}
	}
	long long prod = lcm1[n - 1] * ((l - 1) / lcm1[n - 1] + 1);
	return prod <= h ? prod : -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i){
		int n;
		long long l, h;
		cin >> n >> l >> h;
		vector<long long> f(n);
		for(int j = 0; j < n; ++j){
			cin >> f[j];
		}
		long long ans = solve(f, n, l, h);
		if(ans != -1){
			cout << "Case #" << i << ": " << ans << "\n";
		}else{
			cout << "Case #" << i << ": NO\n";
		}
	}
	return 0;
}
