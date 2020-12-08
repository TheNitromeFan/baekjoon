#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

class Cmp{
	public:
		bool operator()(tuple<int, int, int> a, tuple<int, int, int> b){
			return (long long)get<2>(a) * get<1>(b) > (long long)get<2>(b) * get<1>(a)
			|| ((long long)get<2>(a) * get<1>(b) == (long long)get<2>(b) * get<1>(a) && get<1>(a) < get<1>(b))
			|| ((long long)get<2>(a) * get<1>(b) == (long long)get<2>(b) * get<1>(a) && get<1>(a) == get<1>(b) && get<0>(a) < get<0>(b));
		}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<tuple<int, int, int>> games(n);
	for(int i = 0; i < n; ++i){
		int num, cost, happy;
		cin >> num >> cost >> happy;
		games[i] = make_tuple(num, cost, happy);
	}
	sort(games.begin(), games.end(), Cmp());
	for(int i = 0; i < k; ++i){
		cout << get<0>(games[i]) << '\n';
	}
	return 0;
}
