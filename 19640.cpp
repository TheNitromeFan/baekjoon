#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#define MAX 100001

using namespace std;

int m;

class Cmp{
	public:
		bool operator()(tuple<int, int, int> a, tuple<int, int, int> b){
			return get<0>(a) < get<0>(b) || (get<0>(a) == get<0>(b) && get<1>(a) < get<1>(b))
			|| (get<0>(a) == get<0>(b) && get<1>(a) == get<1>(b) && get<2>(a) % m > get<2>(b) % m);
		}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> m >> k;
	queue<tuple<int, int, int>> q[MAX];
	for(int i = 0; i < n; ++i){
		int di, hi;
		cin >> di >> hi;
		q[i % m].push(make_tuple(di, hi, i));
	}
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, Cmp> pq;
	for(int i = 0; i < m; ++i){
		tuple<int, int, int> person = q[i].front();
		q[i].pop();
		pq.push(person);
	}
	int cnt = 0;
	while(true){
		tuple<int, int, int> person = pq.top();
		pq.pop();
		// cout << get<0>(person) << ' ' << get<1>(person) << ' ' << get<2>(person) << '\n';
		int num = get<2>(person);
		if(num == k){
			break;
		}
		++cnt;
		if(q[num % m].empty()){
			continue;
		}
		tuple<int, int, int> person1 = q[num % m].front();
		q[num % m].pop();
		pq.push(person1);
	}
	cout << cnt;
	return 0;
}
