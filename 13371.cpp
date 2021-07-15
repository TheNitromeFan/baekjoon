#include <iostream>
#include <cmath>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		long long n;
		cin >> n;
		long long m = (long long)sqrt(2 * n / 3.0) - 2;
		while(3 * m * (m + 1) / 2 < n){
			++m;
		}
		if(n == 1){
			cout << "1 dolphin" << '\n';
			continue;
		}else if(n == 2){
			cout << "1 jump" << '\n';
			continue;
		}
		n -= 3 * (m - 1) * m / 2;
		if(n <= m){
			cout << m << " dolphins" << '\n';
		}else if(n <= 2 * m){
			cout << m << " jumps" << '\n';
		}else{
			cout << "splash" << '\n';
		}
	}
	return 0;
}
