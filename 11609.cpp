#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<string, string>> names;
	names.resize(n);
	for(int i = 0; i < n; ++i){
		cin >> names[i].second >> names[i].first;
	}
	sort(names.begin(), names.end());
	for(auto name : names){
		cout << name.second << ' ' << name.first << '\n';
	}
	return 0;
}
