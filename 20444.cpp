#include <iostream>

using namespace std;

bool cut(long long n, long long k){
	long long low = 0, high = n / 2;
	while(low <= high){
		long long mid = (low + high) / 2;
		long long x = mid, y = n - x;
		if((x + 1) * (y + 1) == k){
			return true;
		}else if((x + 1) * (y + 1) < k){
			low = mid + 1;
		}else{
			high = mid - 1;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n, k;
	cin >> n >> k;
	cout << (cut(n, k) ? "YES" : "NO");
	return 0;
}
