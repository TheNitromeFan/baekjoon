#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> t(n);
	for(int i = 0; i < n; ++i){
		cin >> t[i];
	}
	long long penalty = 0, time = 0;
	vector<int> kproblems;
	for(int i = 0; i < k; ++i){
		kproblems.push_back(t[i]);
	}
	for(int i = k; i < n; ++i){
		sort(kproblems.begin(), kproblems.end(), greater<int>());
		time += kproblems.back();
		penalty += time;
		kproblems.pop_back();
		kproblems.push_back(t[i]);
	}
	sort(kproblems.begin(), kproblems.end(), greater<int>());
	while(!kproblems.empty()){
		time += kproblems.back();
		penalty += time;
		kproblems.pop_back();
	}
	cout << penalty;
	return 0;
}
