#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

bool cmp(tuple<string, int, int, int> a, tuple<string, int, int, int> b){
	return get<3>(a) > get<3>(b) || (get<3>(a) == get<3>(b) && (get<2>(a) > get<2>(b) || (get<2>(a) == get<2>(b) && get<1>(a) > get<1>(b))));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<tuple<string, int, int, int>> v;
	v.resize(n);
	for(int i = 0; i < n; ++i){
		cin >> get<0>(v[i]) >> get<1>(v[i]) >> get<2>(v[i]) >> get<3>(v[i]);
	}
	sort(v.begin(), v.end(), cmp);
	cout << get<0>(v[0]) << '\n' << get<0>(v[n - 1]);
	return 0;
}
