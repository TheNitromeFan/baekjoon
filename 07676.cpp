#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int r, n;
		cin >> r >> n;
		if(r == -1 && n == -1){
			break;
		}
		vector<int> v(n);
		for(int i = 0; i < n; ++i){
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		int cnt = 0;
		int i = 0;
		while(i < n){
			++cnt;
			int j = i;
			while(j + 1 < n && v[j + 1] - v[i] <= r){
				++j;
			}
			i = j;
			while(i < n && v[i] - v[j] <= r){
				++i;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
