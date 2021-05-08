#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<long long> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int ans1 = 0, ans2 = 1, ans3 = 2;
	for(int i = 0; i < n; ++i){
		for(int j = i + 1; j < n; ++j){
			int idx = lower_bound(v.begin() + j + 1, v.end(), -(v[i] + v[j])) - v.begin();
			for(int k = max(j + 1, idx - 2); k < min(n, idx + 3); ++k){
				if(llabs(v[i] + v[j] + v[k]) < llabs(v[ans1] + v[ans2] + v[ans3])){
					ans1 = i;
					ans2 = j;
					ans3 = k;
				}
			}
		}
	}
	cout << v[ans1] << ' ' << v[ans2] << ' ' << v[ans3];
	return 0;
}
