#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> wages(n);
	for(int i = 0; i < n; ++i){
		cin >> wages[i];
	}
	long long ans = 0;
	for(int i = 0; i < m; ++i){
		ans += wages[i];
	}
	long long cmp = ans;
	for(int i = m, j = 0; i < n; ++i, ++j){
		cmp += wages[i] - wages[j];
		if(cmp > ans){
			ans = cmp;
		}
	}
	cout << ans;
	return 0;
}
