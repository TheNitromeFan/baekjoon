#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int sum = 0, min = 1001;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		if(x % 2 == 0){
			--x;
		}
		sum += x;
		if(x < min){
			min = x;
		}
	}
	if(n % 2 == 0){
		sum -= min;
	}
	cout << sum;
	return 0;
}
