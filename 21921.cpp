#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x;
	cin >> n >> x;
	vector<int> visitors(n);
	for(int i = 0; i < n; ++i){
		cin >> visitors[i];
	}
	int rolling_sum = 0;
	for(int i = 0; i < x; ++i){
		rolling_sum += visitors[i];
	}
	int max_rolling_sum = rolling_sum;
	int cnt = 1;
	for(int i = x; i < n; ++i){
		rolling_sum += visitors[i] - visitors[i - x];
		if(max_rolling_sum < rolling_sum){
			max_rolling_sum = rolling_sum;
			cnt = 1;
		}else if(max_rolling_sum == rolling_sum){
			++cnt;
		}
	}
	if(max_rolling_sum > 0){
		cout << max_rolling_sum << '\n' << cnt << '\n';
	}else{
		cout << "SAD\n";
	}
	return 0;
}
