#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <map>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	map<tuple<string, string, string>, int> cnt;
	int ans = 0;
	for(int i = 0; i < n; ++i){
		vector<string> cows(3, "");
		for(int j = 0; j < 3; ++j){
			cin >> cows[j];
		}
		sort(cows.begin(), cows.end());
		tuple<string, string, string> trio = make_tuple(cows[0], cows[1], cows[2]);
		if(cnt.find(trio) == cnt.end()){
			cnt[trio] = 1;
		}else{
			++cnt[trio];
		}
		if(ans < cnt[trio]){
			ans = cnt[trio];
		}
	}
	cout << ans;
	return 0;
}
