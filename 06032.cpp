#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

class Cmp{
	public:
		bool operator()(tuple<int, int, int> a, tuple<int, int, int> b){
			return get<1>(a) / (double)get<2>(a) > get<1>(b) / (double)get<2>(b);
		}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<tuple<int, int, int>> v(n);
	for(int i = 0; i < n; ++i){
		cin >> get<1>(v[i]) >> get<2>(v[i]);
		get<0>(v[i]) = i + 1;
	}
	sort(v.begin(), v.end(), Cmp());
	cout << get<2>(v[0]) + get<2>(v[1]) + get<2>(v[2]) << '\n'
	<< get<0>(v[0]) << '\n' << get<0>(v[1]) << '\n' << get<0>(v[2]);
	return 0;
}
