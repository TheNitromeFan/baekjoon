#include <iostream>

using namespace std;

long long gcd(long long a, long long b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

long long lcm(long long a, long long b){
	return a / gcd(a, b) * b;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		long long a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << lcm(a, c) << ' ' << gcd(b, d) << '\n';
	}
	return 0;
}
