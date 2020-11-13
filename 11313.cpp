#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>

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
	map<pair<string, string>, pair<pair<string, string>, pair<string, string>>> m;
	for(int i = 0; i < n; i += 3){
		m[names[i]] = make_pair(names[i + 1], names[i + 2]);
		m[names[i + 1]] = make_pair(names[i], names[i + 2]);
		m[names[i + 2]] = make_pair(names[i], names[i + 1]);
	}
	int q;
	cin >> q;
	for(int j = 0; j < q; ++j){
		pair<string, string> name;
		cin >> name.second >> name.first;
		cout << m[name].first.second << ' ' << m[name].first.first << '\n';
		cout << m[name].second.second << ' ' << m[name].second.first << '\n';
	}
	return 0;
}
