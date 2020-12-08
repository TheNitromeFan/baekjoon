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
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < i; ++j){
			for(int k = 0; k < j; ++k){
				if(v[i] - v[j] >= v[j] - v[k] && v[i] - v[j] <= 2 * (v[j] - v[k])){
					++cnt;
				}
			}
		}
	}
	cout << cnt;
	return 0;
}
