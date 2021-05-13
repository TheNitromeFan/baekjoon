#include <iostream>
#include <algorithm>

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
	long long a, b, c, d;
	cin >> a >> b >> c >> d;
	long long cnt = 0;
	for(int sum = 2; sum <= 999; ++sum){
		for(int x = 1, y = sum - 1; y >= 1; ++x, --y){
			if(gcd(x, y) != 1){
				continue;
			}
			cnt += max(0LL, min(b / x, d / y) - max((a - 1) / x, (c - 1) / y));
		}
	}
	cout << cnt;
	return 0;
}
