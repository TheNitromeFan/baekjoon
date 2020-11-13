#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>

using namespace std;

bool cmp(tuple<string, int, int, int> a, tuple<string, int, int, int> b){
	return get<1>(a) > get<1>(b) || (get<1>(a) == get<1>(b) && (get<2>(a) < get<2>(b) || (get<2>(a) == get<2>(b) && (get<3>(a) > get<3>(b) || (get<3>(a) == get<3>(b) && get<0>(a) < get<0>(b))))));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<tuple<string, int, int, int>> v;
	v.resize(n);
	for(int i = 0; i < n; ++i){
		string name;
		int k, e, m;
		cin >> name >> k >> e >> m;
		v[i] = make_tuple(name, k, e, m);
	}
	sort(v.begin(), v.end(), cmp);
	for(int i = 0; i < n; ++i){
		cout << get<0>(v[i]) << '\n';
	}
	return 0;
}
