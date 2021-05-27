#include <iostream>
#include <cstdlib>
#include <unordered_map>

long long gcd(long long a, long long b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	unordered_map<long long, long long> m;
	for(int i = 0; i < n; ++i){
		long long a, b, c;
		cin >> a >> b >> c;
		if(a == 0){
			++m[1];
			continue;
		}
		if(a < 0){
			a *= -1;
			b *= -1;
		}
		long long g = gcd(a, llabs(b));
		a /= g;
		b /= g;
		++m[a * 2000000000 + b];
	}
	long long sum1 = 0, sum2 = 0;
	for(unordered_map<long long, long long>::iterator it1 = m.begin(); it1 != m.end(); ++it1){
		sum1 += it1->second;
		sum2 += it1->second * it1->second;
	}
	cout << (sum1 * sum1 - sum2) / 2;
	return 0;
}
