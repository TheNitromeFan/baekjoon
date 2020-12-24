#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstring>

using namespace std;

int dp[7][5000001];

int calculate(vector<int> &digits, int n, int w, int target, int cur){
	if(cur == target && w == 0){
		return 1;
	}else if(cur > target || w == 0){
		return 0;
	}
	if(dp[w][cur] != -1){
		return dp[w][cur];
	}
	dp[w][cur] = 0;
	for(int digit : digits){
		if(calculate(digits, n, w - 1, target, cur * digit)){
			dp[w][cur] = 1;
			break;
		}else if(calculate(digits, n, w - 1, target, cur + digit)){
			dp[w][cur] = 1;
			break;
		}
	}
	return dp[w][cur];
}

bool can_calculate(vector<int> &digits, int n, int w, int target){
	for(int digit : digits){
		if(calculate(digits, n, w, target, digit)){
			return true;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int w;
	cin >> w;
	int d;
	cin >> d;
	vector<int> digits(d);
	for(int i = 0; i < d; ++i){
		cin >> digits[i];
	}
	sort(digits.begin(), digits.end(), greater<int>());
	int v;
	cin >> v;
	for(int j = 0; j < v; ++j){
		memset(dp, -1, sizeof(dp));
		int x;
		cin >> x;
		cout << (can_calculate(digits, d, w, x) ? 'Y' : 'N') << '\n';
	}
	return 0;
}
