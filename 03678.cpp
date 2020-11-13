#include <cstdio>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

map<int, int> cnt;

bool cmp(pair<int, int> a, pair<int, int> b){
	return a.second < b.second || (a.second == b.second && (cnt[a.first] < cnt[b.first] || (cnt[a.first] == cnt[b.first] && a.first < b.first)));
}

void preprocess(vector<int> &move){
	for(int resource = 1; resource <= 5; ++resource){
		cnt[resource] = 0;
	}
	int dp[60][360] = {};
	dp[0][0] = 1;
	++cnt[1];
	move.push_back(0);
	move.push_back(1);
	for(int i = 1; i < 60; ++i){
		for(int j = 0; j < 6 * i; ++j){
			vector<pair<int, int>> candidates;
			for(int k = 1; k <= 5; ++k){
				candidates.push_back(make_pair(k, 0));
			}
			if(j % i == 0){
				int x = dp[i - 1][j / i * (i - 1)];
				++candidates[x - 1].second;
			}else{
				int x = dp[i - 1][j / i * (i - 1) + (j % i - 1)], y = dp[i - 1][j / i * (i - 1) + (j % i)];
				++candidates[x - 1].second;
				++candidates[y - 1].second;
			}
			if(j > 0){
				int z = dp[i][j - 1];
				++candidates[z - 1].second;
			}
			sort(candidates.begin(), candidates.end(), cmp);
			dp[i][j] = candidates[0].first;
			move.push_back(dp[i][j]);
			++cnt[dp[i][j]];
		}
	}
}

int main(){
	vector<int> ans;
	preprocess(ans);
	int c;
	scanf("%d", &c);
	for(int a0 = 0; a0 < c; ++a0){
		int x;
		scanf("%d", &x);
		printf("%d\n", ans[x]);
	}
	return 0;
}
