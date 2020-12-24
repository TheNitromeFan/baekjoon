#include <iostream>

using namespace std;

long long gcd(long long m, long long n){
	if(n == 0){
		return m;
	}else{
		return gcd(n, m % n);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long m, n;
	cin >> m >> n;
	long long g = gcd(m, n);
	m /= g;
	n /= g;
	cout << (m % 2 == 1 && n % 2 == 1 ? g : 0);
	return 0;
}
