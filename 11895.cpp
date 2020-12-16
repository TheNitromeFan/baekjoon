#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int running_xor = 0, sum = 0, min = 10000000;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		running_xor ^= x;
		sum += x;
		if(min > x){
			min = x;
		}
	}
	if(running_xor == 0){
		cout << sum - min;
	}else{
		cout << 0;
	}
	return 0;
}
