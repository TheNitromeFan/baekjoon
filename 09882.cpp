#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int evaluate(vector<vector<int>> &teams){
	vector<int> a(4);
	for(int i = 0; i < 4; ++i){
		for(int j = 0; j < 3; ++j){
			a[i] += teams[i][j];
		}
	}
	sort(a.begin(), a.end());
	return a[3] - a[0];
}

int calc(vector<vector<int>> &teams, vector<int> &skills, int pos){
	if(pos == 12){
		return evaluate(teams);
	}
	int ret = 1000000000;
	for(int i = 0; i < 4; ++i){
		if(teams[i].size() < 3){
			teams[i].push_back(skills[pos]);
			int cmp = calc(teams, skills, pos + 1);
			if(ret > cmp){
				ret = cmp;
			}
			teams[i].pop_back();
			if(teams[i].empty()){
				break;
			}
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<int> skills(12);
	for(int i = 0; i < 12; ++i){
		cin >> skills[i];
	}
	vector<vector<int>> teams(4);
	cout << calc(teams, skills, 0);
	return 0;
}
