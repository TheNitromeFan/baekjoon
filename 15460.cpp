#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int score[MAX];
	for(int i = 1; i <= n; ++i){
		cin >> score[i];
	}
	int sum = score[n] + score[n - 1], lowest = min(score[n], score[n - 1]);
	vector<int> ans = {n - 2};
	double max_avg = sum - lowest;
	for(int k = n - 3; k >= 1; --k){
		sum += score[k + 1];
		lowest = min(lowest, score[k + 1]);
  		double avg = (sum - lowest) / (double)(n - k - 1);
		if(avg > max_avg){
			ans.clear();
			ans.push_back(k);
   			max_avg = avg;
		}else if(avg == max_avg){
			ans.push_back(k);
		}
	}
	sort(ans.begin(), ans.end());
	for(int x : ans){
		cout << x << '\n';
	}
	return 0;
}
