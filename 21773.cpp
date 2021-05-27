#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

class Cmp{
	public:
		bool operator()(tuple<int, int, int> x, tuple<int, int, int> y){
			return get<2>(x) < get<2>(y)
			|| (get<2>(x) == get<2>(y) && get<0>(x) > get<0>(y));
		}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n;
	cin >> t >> n;
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, Cmp> pq;
	for(int i = 0; i < n; ++i){
		int a, b, c;
		cin >> a >> b >> c;
		pq.push(make_tuple(a, b, c));
	}
	for(int time = 1; time <= t && !pq.empty(); ++time){
		tuple<int, int, int> x = pq.top();
		pq.pop();
		cout << get<0>(x) << '\n';
		--get<1>(x);
		--get<2>(x);
		if(get<1>(x) > 0){
			pq.push(x);
		}
	}
	return 0;
}
