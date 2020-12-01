#include <iostream>

using namespace std;

int gcd(int a, int b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int d1, d2;
	cin >> d1 >> d2;
	static bool seats[2001][2001] = {};
	int cnt = 0;
	for(int n = d1; n <= d2; ++n){
		for(int i = 0; i < n; ++i){
			int g = gcd(i, n);
			if(!seats[i / g][n / g]){
				++cnt;
				seats[i / g][n / g] = true;
			}
		}
	}
	cout << cnt;
	return 0;
}
