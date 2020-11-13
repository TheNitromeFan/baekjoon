#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, string> a, pair<int, string> b){
	return a.first < b.first;
}

int main(){
	int n;
	cin >> n;
	vector<pair<int, string>> v;
	pair<int, string> tmp(0, "");
	v.resize(n, tmp);
	for(int i = 0; i < n; ++i){
		cin >> v[i].first >> v[i].second;
	}
	stable_sort(v.begin(), v.end(), compare);
	for(int i = 0; i < n; ++i){
		cout << v[i].first << ' ' << v[i].second << '\n';
	}
	return 0;
}
