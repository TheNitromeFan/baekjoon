#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int d;
	cin >> d;
	for(int a0 = 0; a0 < d; ++a0){
		int n, k;
		cin >> n >> k;
		vector<int> v(n);
		for(int i = 0; i < n; ++i){
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		cout << v[k - 1] << '\n';
	}
	return 0;
}
