#include <iostream>
#include <algorithm>

using namespace std;

long long score(long long a, long long b, long long c){
	return a * a + b * b + c * c + 7 * c;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		long long a, b, c, d;
		cin >> a >> b >> c >> d;
		if(a < b){
			swap(a, b);
		}
		if(b < c){
			swap(b, c);
		}
		if(a < b){
			swap(a, b);
		}
		long long ans = score(a + d, b, c);
		for(int j = 0; j < 50; ++j){
			long long addA = max(0LL, j - a), addB = max(0LL, j - b), addC = max(0LL, j - c);
			if(addA + addB + addC <= d){
				ans = max(ans, score(a + (d - addB - addC), b + addB, c + addC));
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
