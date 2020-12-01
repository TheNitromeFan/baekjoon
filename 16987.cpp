#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int break_eggs(vector<pair<int, int>> &eggs, vector<bool> &broken, int n, int cur){
	if(cur == n){
		return 0;
	}
	if(broken[cur]){
		return break_eggs(eggs, broken, n, cur + 1);
	}
	int ret = 0;
	for(int i = 0; i < n; ++i){
		int cnt = 0;
		if(i == cur || broken[i]){
			continue;
		}
		eggs[i].first -= eggs[cur].second;
		eggs[cur].first -= eggs[i].second;
		if(eggs[i].first <= 0){
			broken[i] = true;
			++cnt;
		}
		if(eggs[cur].first <= 0){
			broken[cur] = true;
			++cnt;
		}
		int cmp = break_eggs(eggs, broken, n, cur + 1);
		if(ret < cnt + cmp){
			ret = cnt + cmp;
		}
		broken[i] = false;
		broken[cur] = false;
		eggs[i].first += eggs[cur].second;
		eggs[cur].first += eggs[i].second;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<int, int>> eggs(n);
	for(int i = 0; i < n; ++i){
		cin >> eggs[i].first >> eggs[i].second;
	}
	vector<bool> broken(n);
	cout << break_eggs(eggs, broken, n, 0);
	return 0;
}
