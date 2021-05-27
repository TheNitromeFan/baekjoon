#include <iostream>
#include <deque>
#define MAX 100001

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	int a[MAX] = {};
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
	}
	long long psum[MAX] = {};
	for(int i = 1; i <= n; ++i){
		psum[i] = psum[i - 1] + a[i];
	}
	long long dp[MAX] = {};
	deque<int> dq;
	for(int i = 1; i <= n; ++i){
		while(!dq.empty() && dq.front() < i - k){
			dq.pop_front();
		}
		while(!dq.empty() && dp[dq.back() - 1] - psum[dq.back()] <= dp[i - 1] - psum[i]){
			dq.pop_back();
		}
		dq.push_back(i);
		dp[i] = psum[i] + dp[dq.front() - 1] - psum[dq.front()];
		if(i <= k && dp[i] < psum[i]){
			dp[i] = psum[i];
		}
	}
	cout << dp[n];
	return 0;
}
