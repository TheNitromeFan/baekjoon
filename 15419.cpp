#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<long long> a(3), b(n);
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		a[i % 3] += x;
	}
	for(int i = 0; i < n; ++i){
		cin >> b[i];
	}
	vector<long long> ans(3);
	for(int i = 0; i < 3; ++i){
		for(int j = 0; j < n; ++j){
			ans[(i + j + 2) % 3] += a[i] * b[j];
		}
	}
	cout << ans[0] << ' ' << ans[1] << ' ' << ans[2];
	return 0;
}
