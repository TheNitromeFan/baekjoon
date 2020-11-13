#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool cmp(pair<double, string> a, pair<double, string> b){
	return a.first > b.first;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		vector<pair<double, string>> v;
		v.resize(n);
		for(int i = 0; i < n; ++i){
			cin >> v[i].second >> v[i].first;
		}
		stable_sort(v.begin(), v.end(), cmp);
		for(int idx = 0; idx < n && v[idx].first == v[0].first; ++idx){
			cout << v[idx].second << ' ';
		}
		cout << '\n';
	}
	return 0;
}
