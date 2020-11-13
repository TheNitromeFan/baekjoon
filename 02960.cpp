#include <iostream>

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	bool crossed[1001];
	for(int i = 2; i <= n; ++i){
		crossed[i] = false;
	}
	int cntr = 0;
	for(int i = 2; i <= n; ++i){
		if(crossed[i]){
			continue;
		}
		for(int m = 1; i * m <= n; ++m){
			if(crossed[i * m]){
				continue;
			}
			crossed[i * m] = true;
			++cntr;
			if(cntr == k){
				cout << i * m;
				return 0;
			}
		}
	}
	return -1;
}
