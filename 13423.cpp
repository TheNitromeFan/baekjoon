#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		cin >> n;
		vector<int> v(n);
		set<int> s;
		for(int &vi : v){
			cin >> vi;
			s.insert(vi);
		}
		sort(v.begin(), v.end());
		int cnt = 0;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < i; ++j){
				if(s.find(2 * v[i] - v[j]) != s.end()){
					++cnt;
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
