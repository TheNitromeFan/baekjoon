#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> ab(n);
	for(int i = 0; i < n; ++i){
		cin >> ab[i].first;
	}
	for(int i = 0; i < n; ++i){
		cin >> ab[i].second;
	}
	sort(ab.begin(), ab.end(), [](pair<int, int> abi, pair<int, int> abj){
		return abi.second > abj.second;
	});
	vector<bool> taken(k + 1);
	vector<int> unemployed;
	int jobs = 0;
	long long time = 0;
	for(int i = 0; i < n; ++i){
		int job = ab[i].first, convince = ab[i].second;
		if(!taken[job]){
			taken[job] = true;
			++jobs;
		}else{
			unemployed.push_back(convince);
		}
	}
	reverse(unemployed.begin(), unemployed.end());
	for(int i = 0; jobs < k; ++i, ++jobs){
		time += unemployed[i];
	}
	cout << time;
	return 0;
}
