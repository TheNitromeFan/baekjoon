#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool simulate(vector<long long> &sums, int n, int pos, vector<long long> &ans){
	if(((sums[0] + sums[1] + sums[pos]) & 1) != 0){
		return false;
	}
	ans.clear();
	vector<bool> used(n * (n - 1) / 2);
	unordered_map<long long, vector<int>> um;
	for(int i = 0; i < n * (n - 1) / 2; ++i){
		um[sums[i]].push_back(i);
	}
	used[um[sums[0]].back()] = true;
	um[sums[0]].pop_back();
	used[um[sums[1]].back()] = true;
	um[sums[1]].pop_back();
	used[um[sums[pos]].back()] = true;
	um[sums[pos]].pop_back();
	ans.push_back((sums[0] + sums[1] - sums[pos]) / 2);
	ans.push_back((sums[0] + sums[pos] - sums[1]) / 2);
	ans.push_back((sums[1] + sums[pos] - sums[0]) / 2);
	int idx = 0;
	for(int j = 3; j < n; ++j){
		while(used[idx]){
			++idx;
		}
		ans.push_back(sums[idx] - ans[0]);
		used[idx] = true;
		for(int i = 1; i < j; ++i){
			if(um[ans[i] + ans[j]].empty()){
				// cout << ans.size() << ' ' << idx << '\n';
				ans.clear();
				return false;
			}
			used[um[ans[i] + ans[j]].back()] = true;
			um[ans[i] + ans[j]].pop_back();
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<long long> sums(n * (n - 1) / 2);
	for(int i = 0; i < n * (n - 1) / 2; ++i){
		cin >> sums[i];
	}
	sort(sums.begin(), sums.end());
	if(n == 2){
		if(sums[0] >= 0){
			cout << 0 << ' ' << sums[0];
		}else{
			cout << sums[0] << ' ' << 0;
		}
		return 0;
	}
	vector<long long> ans(n);
	for(int pos = 2; pos < n * (n - 1) / 2; ++pos){
		if(simulate(sums, n, pos, ans)){
			for(long long x : ans){
				cout << x << ' ';
			}
			return 0;
		}
	}
	cout << "Impossible";
	return 0;
}
