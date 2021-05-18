#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int g;
	cin >> g;
	vector<int> ans;
	for(int d1 = 1; d1 * d1 < g; ++d1){
		if(g % d1 != 0){
			continue;
		}
		int d2 = g / d1;
		if(d1 % 2 == d2 % 2)
		ans.push_back((d1 + d2) / 2);
	}
	sort(ans.begin(), ans.end());
	if(!ans.empty()){
		for(int x : ans){
			cout << x << '\n';
		}
	}else{
		cout << -1 << '\n';
	}
	return 0;
}
