#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int f, m, n;
	cin >> f >> m >> n;
	vector<pair<int, int>> fm(n);
	for(int i = 0; i < n; ++i){
		cin >> fm[i].first >> fm[i].second;
	}
	int ans_f = f, ans_m = m, ans_parts = 0;
	for(int parts = 0; parts < (1 << n); ++parts){
		int x = parts;
		vector<bool> use(n);
		int agg_f = f, agg_m = m;
		for(int i = 0; i < n; ++i){
			if(x % 2 == 1){
				use[i] = true;
				agg_f += fm[i].first;
				agg_m += fm[i].second;
			}
			x /= 2;
		}
		if((long long)agg_f * ans_m > (long long)ans_f * agg_m
		|| ((long long)agg_f * ans_m == (long long)ans_f * agg_m && agg_m < ans_m)){
			ans_f = agg_f;
			ans_m = agg_m;
			ans_parts = parts;
		}
	}
	vector<int> nums;
	for(int i = 0; i < n; ++i){
		if(ans_parts % 2 == 1){
			nums.push_back(i + 1);
		}
		ans_parts /= 2;
	}
	if(nums.size() > 0){
		for(int x : nums){
			cout << x << '\n';
		}
	}else{
		cout << "NONE";
	}
	return 0;
}
