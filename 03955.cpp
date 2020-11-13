#include <iostream>

using namespace std;

long long gcd(long long a, long long b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

long long extended_gcd(long long a, long long b){
	long long copyA = a;
	long long s = 0, t = 1;
	while(b > 0){
		long long q = a / b;
		long long r = a % b;
		long long tmp = s - q * t;
		a = b;
		b = r;
		s = t;
		t = tmp;
	}
	while(s < 0){
		s += copyA;
	}
	return s;
}

int main(){
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		long long k, c;
		cin >> k >> c;
		if(c == 1){
			if(k + 1 > 1000000000){
				cout << "IMPOSSIBLE\n";
			}else{
				cout << k + 1 << '\n';
			}
		}else if(k == 1){
			cout << 1 << '\n';
		}else if(gcd(k, c) > 1){
			cout << "IMPOSSIBLE\n";
		}else{
			long long ans = extended_gcd(k, c);
			if(ans > 1000000000){
				cout << "IMPOSSIBLE\n";
			}else{
				cout << ans << '\n';
			}
		}
	}
	return 0;
}
