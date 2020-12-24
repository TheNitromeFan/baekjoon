#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

bool majorize(vector<tuple<int, int, int, int>> &v, int n){
	sort(v.begin(), v.end(), [](tuple<int, int, int, int> a, tuple<int, int, int, int> b){
		return make_pair(get<1>(a) - get<0>(a), get<3>(a) - get<2>(a))
		> make_pair(get<1>(b) - get<0>(b), get<3>(b) - get<2>(b));
	});
	for(int i = 1; i < n; ++i){
		if(!(get<0>(v[i]) >= get<0>(v[0]) && get<1>(v[i]) <= get<1>(v[0])
		&& get<2>(v[i]) >= get<2>(v[0]) && get<3>(v[i]) <= get<3>(v[0]))){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int n;
		cin >> n;
		vector<tuple<int, int, int, int>> v(n);
		for(int j = 0; j < n; ++j){
			int x1, x2, y1, y2;
			cin >> x1 >> x2 >> y1 >> y2;
			v[j] = make_tuple(x1, x2, y1, y2);
		}
		cout << (majorize(v, n) ? "TAK" : "NIE") << "\n";
	}
	return 0;
}
