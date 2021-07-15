#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long d, p, q;
	cin >> d >> p >> q;
	if(p < q){
		swap(p, q);
	}
	long long ans = 10000000000000000LL;
	for(long long x = 0; x < q && x <= d / p + 1; ++x){
		long long ymax = (d - p * x) / q;
		for(long long y = max(0LL, ymax - 2); y <= ymax + 1; ++y){
			if(p * x + q * y >= d){
				ans = min(ans, p * x + q * y);
			}
		}
	}
	cout << ans << '\n';
	return 0;
}
