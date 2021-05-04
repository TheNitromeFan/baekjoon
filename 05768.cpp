#include <iostream>

using namespace std;

int divisors(int x){
	int ret = 1;
	for(int p = 2; p * p <= x; ++p){
		int cnt = 1;
		while(x % p == 0){
			x /= p;
			++cnt;
		}
		ret *= cnt;
	}
	if(x > 1){
		ret *= 2;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int m, n;
		cin >> m >> n;
		if(m == 0 && n == 0){
			break;
		}
		int x = n, y = 1;
		for(int i = n; i >= m; --i){
			int j = divisors(i);
			if(j > y){
				x = i;
				y = j;
			}
		}
		cout << x << ' ' << y << '\n';
	}
	return 0;
}
