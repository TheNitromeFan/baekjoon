#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool muscle(vector<pair<int, int>> &weights, int n, int k){
	int sum = 0;
	for(int i = 0; i < n; ++i){
		sum += weights[i].first - k;
		if(sum < 0){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> weights(n);
	for(int i = 0; i < n; ++i){
		cin >> weights[i].first;
		weights[i].second = i + 1;
	}
	sort(weights.begin(), weights.end());
	int cnt = 0;
	do{
		if(muscle(weights, n, k)){
			++cnt;
		}
	}while(next_permutation(weights.begin(), weights.end()));
	cout << cnt;
	return 0;
}
