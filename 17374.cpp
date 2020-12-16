#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		long long p, q, a, b, c, d;
		cin >> p >> q >> a >> b >> c >> d;
		long long coins = 0;
		coins += q / c * d;
		q %= c;
		long long bitcoins = 0;
		long long m = min(p, coins);
		bitcoins += m;
		p -= m;
		coins -= m;
		bitcoins += p / (a + b) * b;
		p %= (a + b);
		bitcoins += coins / (a + b) * a;
		coins %= (a + b);
		while(p >= a){
			p -= a;
			coins += b;
			m = min(p, coins);
			bitcoins += m;
			p -= m;
			coins -= m;
		}
		while(coins >= b){
			coins -= b;
			p += a;
			m = min(p, coins);
			bitcoins += m;
			p -= m;
			coins -= m;
		}
		cout << bitcoins << '\n';
	}
	return 0;
}
