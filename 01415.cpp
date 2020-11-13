#include <iostream>
#include <vector>

using namespace std;

bool is_not_prime[500001];

void preprocess(){
	is_not_prime[0] = true;
	is_not_prime[1] = true;
	for(int i = 2; i * i <= 500000; ++i){
		if(is_not_prime[i]){
			continue;
		}
		for(int j = i; j * i <= 500000; ++j){
			is_not_prime[j * i] = true;
		}
	}
}

int main(){
	preprocess();
	int n;
	cin >> n;
	vector<int> candies;
	int zero_cnt = 1;
	int candy_cnt[10001] = {};
	for(int i = 0; i < n; ++i){
		int candy;
		cin >> candy;
		if(candy == 0){
			++zero_cnt;
			continue;
		}
		if(candy_cnt[candy] == 0){
			candies.push_back(candy);
		}
		++candy_cnt[candy];
	}
	static long long dp[500000] = {}; // dp[i]: # of ways up to add up to i
	dp[0] = 1;
	for(int cur: candies){
		for(int i = 500000; i >= 0; --i){
			for(int cnt = 1; cnt <= candy_cnt[cur] && i - cur * cnt >= 0; ++cnt){
				dp[i] += dp[i - cur * cnt];
			}
		}
	}
	long long ans = 0;
	for(int i = 0; i <= 500000; ++i){
		if(!is_not_prime[i]){
			ans += dp[i];
		}
	}
	cout << ans * zero_cnt;
	return 0;
}
