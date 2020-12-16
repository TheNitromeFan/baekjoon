#include <iostream>
#include <cmath>

using namespace std;

long long jumps(long long n){
	long long low = 1, high = (long long)sqrt(2 * n) + 1;
	while(low < high){
		long long mid = (low + high) / 2;
		// cout << mid << ' ';
		long long triangle = 0;
		if(mid % 2 == 0){
			triangle = (mid / 2) * (mid + 1);
		}else{
			triangle = ((mid + 1) / 2) * mid;
		}
		// cout << triangle << '\n';
		if(triangle <= n){
			low = mid + 1;
		}else{
			high = mid;
		}
	}
	return low - 1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		long long n;
		cin >> n;
		cout << jumps(n) << '\n';
	}
	return 0;
}
