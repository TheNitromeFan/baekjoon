#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	int ans = 1000000000;
	for(int i = 0; i < n; ++i){
		int sum = 0;
		for(int j = 0; j < n; ++j){
			sum += v[j] * ((j - i + n) % n);
		}
		if(ans > sum){
			ans = sum;
		}
	}
	cout << ans;
	return 0;
}
