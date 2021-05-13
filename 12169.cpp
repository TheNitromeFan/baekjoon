#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 1; a0 <= t; ++a0){
		int d;
		cin >> d;
		vector<int> p(d);
		for(int i = 0; i < d; ++i){
			cin >> p[i];
		}
		int ans = 1001;
		for(int j = 1; j <= 1000; ++j){
			int time = j;
			for(int x : p){
				time += (x - 1) / j;
			}
			ans = min(ans, time);
		}
		cout << "Case #" << a0 << ": " << ans << "\n";
	}
	return 0;
}
