#include <iostream>

using namespace std;

static int a[1000001];

int num_of_divisors(int n){
	int ans = 1;
	int exp;
	for(int p = 2; p*p <= n; ++p){
		exp = 0;
		while(n % p == 0){
			n /= p;
			++exp;
		}
		ans *= exp + 1;
	}
	if(n > 1){
		ans *= 2;
	}
	return ans;
}

int main(){
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	for(int q0 = 0; q0 < q; ++q0){
		int t, s, e;
		cin >> t >> s >> e;
		if(t == 1){
			for(int j = s; j <= e; ++j){
				a[j] = num_of_divisors(a[j]);
			}
		}else{
			long long sum = 0;
			for(int j = s; j <= e; ++j){
				sum += a[j];
			}
			cout << sum << '\n';
		}
	}
	return 0;
}
