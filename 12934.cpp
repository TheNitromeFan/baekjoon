#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long x, y;
	cin >> x >> y;
	long long n = 0;
	while(n * (n + 1) / 2 < x + y){
		++n;
	}
	if(n * (n + 1) / 2 > x + y){
		cout << -1;
		return 0;
	}
	int cnt = 0;
	for(long long i = n; i > 0; --i){
		if(i <= x){
			x -= i;
			++cnt;
		}
	}
	cout << cnt;
	return 0;
}
