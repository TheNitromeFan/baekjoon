#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n, m, k;
	cin >> n >> m >> k;
	long long max_white = 0, max_red = 0;
	for(long long x = 1; x <= m; ++x){
		long long white = x % k, red = x / k;
		max_white = max(max_white, white);
		max_red = max(max_red, red);
	}
	cout << n * (max_white + max_red) << '\n';
	return 0;
}
