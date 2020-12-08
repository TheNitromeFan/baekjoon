#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	long long a[1001], psum[1001] = {}, psquaresum[1001] = {};
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		psum[i] = psum[i - 1] + a[i];
		psquaresum[i] = psquaresum[i - 1] + a[i] * a[i];
	}
	for(int k = 1; k <= n; ++k){
		long long maxDev = -1;
		int interv = -1;
		for(int i = 1, j = k; j <= n; ++i, ++j){
			long long sum = psum[j] - psum[i - 1];
			long long squaresum = psquaresum[j] - psquaresum[i - 1];
			if(maxDev < squaresum * k - sum * sum){
				maxDev = squaresum * k - sum * sum;
				interv = i;
			}
		}
		cout << interv << '\n';
	}
	return 0;
}
