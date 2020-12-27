#include <iostream>
#include <algorithm>
#include <cstring>
#define MAXN 100

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> pos(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> pos[i];
	}
	pos.push_back(0);
	sort(pos.begin() + 1, pos.begin() + n + 1);
	int best[MAXN][MAXN][2];
	memset(best, -1, sizeof(best));
	for(int i = 1; i <= n; ++i){
		if(pos[i] == 0){
			best[i][1][0] = 0;
		}
	}
	for(int len = 1; len < n; ++len){
		int ccount = n - len;
		for(int i = 1; i + len <= n + 1; ++i){
			if(best[i][len][0] != -1 && (best[i - 1][len + 1][0] == -1
			|| best[i - 1][len + 1][0] > best[i][len][0] + ccount * (pos[i] - pos[i - 1]))){
				best[i - 1][len + 1][0] = best[i][len][0] + ccount * (pos[i] - pos[i - 1]);
			}
			if(best[i][len][1] != -1 && (best[i - 1][len + 1][0] == -1
			|| best[i - 1][len + 1][0] > best[i][len][1] + ccount * (pos[i + len - 1] - pos[i - 1]))){
				best[i - 1][len + 1][0] = best[i][len][1] + ccount * (pos[i + len - 1] - pos[i - 1]);
			}
			if(best[i][len][0] != -1 && (best[i][len + 1][1] == -1
			|| best[i][len + 1][1] > best[i][len][0] + ccount * (pos[i + len] - pos[i]))){
				best[i][len + 1][1] = best[i][len][0] + ccount * (pos[i + len] - pos[i]);
			}
			if(best[i][len][1] != -1 && (best[i][len + 1][1] == -1
			|| best[i][len + 1][1] > best[i][len][1] + ccount * (pos[i + len] - pos[i + len - 1]))){
				best[i][len + 1][1] = best[i][len][1] + ccount * (pos[i + len] - pos[i + len - 1]);
			}
		}
	}
	int ans;
	if(best[1][n][0] == -1){
		ans = best[1][n][1];
	}else if(best[1][n][1] == -1){
		ans = best[1][n][0];
	}else{
		ans = min(best[1][n][0], best[1][n][1]);
	}
	cout << ans;
	return 0;
}
