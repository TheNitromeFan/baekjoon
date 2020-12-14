#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int groups = 0;
	int idx = 0;
	while(idx < n){
		int capacity = v[idx];
		int members = 0;
		while(idx < n && members < capacity){
			++members;
			++idx;
		}
		++groups;
	}
	cout << groups;
	return 0;
}
