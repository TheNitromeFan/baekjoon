#include <iostream>

using namespace std;

int condos(int n){
	int ret = 0;
	for(int k = 1; k * k <= 2 * n; ++k){
		if(2 * n % k != 0){
			continue;
		}
		int m = 2 * n / k;
		if(m % 2 == k % 2){
			continue;
		}
		int a = (m - k + 1) / 2;
		if(a >= 2){
			++ret;
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		cout << condos(n) << '\n';
	}
	return 0;
}
