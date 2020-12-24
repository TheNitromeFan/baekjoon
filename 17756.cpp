#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int sum = 0, min_odd = 1000000001;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		sum += x;
		if(x % 2 == 1 && x < min_odd){
			min_odd = x;
		}
	}
	if(sum % 2 == 1){
		sum -= min_odd;
	}
	if(sum > 0){
		cout << sum;
	}else{
		cout << "NIESTETY";
	}
	return 0;
}
