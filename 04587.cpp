#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

bool egyptian(vector<long long> &v, long long m, long long n){
	if(m == 1 && n < 1000000){
		v.push_back(n);
		return true;
	}else if(n >= 1000000){
		return false;
	}
	long long d = n / m + 1;
	for(long long k = d; k < 1000000; ++k){
		v.push_back(k);
		long long m1 = m * k - n, n1 = n * k;
		long long g = gcd(m1, n1);
		if(egyptian(v, m1 / g, n1 / g)){
			return true;
		}
		v.pop_back();
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		long long m, n;
		cin >> m >> n;
		if(m == 0 && n == 0){
			break;
		}
		vector<long long> v;
		if(egyptian(v, m, n)){
			for(long long d : v){
				cout << d << ' ';
			}
			cout << '\n';
		}
	}
	return 0;
}
