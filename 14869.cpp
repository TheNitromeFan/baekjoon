#include <iostream>
#include <utility>
#include <deque>
#include <algorithm>
#define MAX 3000
#define MAXVAL 1000000000

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, s, e, t;
	cin >> n >> m >> s >> e >> t;
	int cost[MAX][2 * MAX] = {};
	int exclude[MAX];
	int psum[MAX][2 * MAX + 1] = {};
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> cost[i][j];
			psum[i][j + 1] = psum[i][j] + cost[i][j];
		}
		for(int j = m; j < m + s; ++j){
			psum[i][j + 1] = psum[i][j];
		}
	}
	for(int i = 0; i < n; ++i){
		cin >> exclude[i];
		--exclude[i];
	}
	int dp[MAX][2 * MAX];
	deque<pair<int, int>> dq[MAX];
	for(int i = 0; i < n; ++i){
		fill(dp[i], dp[i] + m + s, MAXVAL);
	}
	int ans = MAXVAL;
	for(int j = 0; j < m + s; ++j){
		if(j >= s){
			pair<int, int> tmp[MAX];
			for(int i = 0; i < n; ++i){
				tmp[i] = make_pair(dp[i][j - s], i);
			}
			sort(tmp, tmp + n);
			for(int i = 0; i < n; ++i){
				for(int k = 0; ; ++k){
					int val = tmp[k].first, vi = tmp[k].second;
					if(val == MAXVAL){
						break;
					}
					if(vi != i && vi != exclude[i]){
						val -= psum[i][j - s + 1];
						while(!dq[i].empty() && dq[i].back().first > val){
							dq[i].pop_back();
						}
						dq[i].push_back(make_pair(val, j - s));
						break;
					}
				}
			}
		}
		for(int i = 0; i < n; ++i){
			if(j >= s - 1 && j < e){
				dp[i][j] = psum[i][j + 1];
			}
			while(!dq[i].empty() && dq[i].front().second < j - e){
				dq[i].pop_front();
			}
			if(!dq[i].empty()){
				dp[i][j] = min(dp[i][j], dq[i].front().first + psum[i][j + 1] + t);
			}
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = m - 1; j < m + s; ++j){
			ans = min(ans, dp[i][j]);
		}
	}
	cout << ans;
	return 0;
}
