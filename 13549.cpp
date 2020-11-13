#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <map>

using std::vector;
using std::priority_queue;
using std::pair;
using std::make_pair;
using std::map;

class Compare{
	public:
		bool operator()(pair<int, int> a, pair<int, int> b){
			return a.second > b.second;
		}
};

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> q;
	map<int, int> m;
	q.push(make_pair(n, 0));
	m[n] = 0;
	while(!q.empty()){
		pair<int, int> p = q.top();
		q.pop();
		int x = p.first, i = p.second;
		// printf("%d %d\n", x, i);
		if(x == k){
			printf("%d", i);
			break;
		}
		if(x < k && (m.find(2 * x) == m.end() || m[2 * x] > i)){
			q.push(make_pair(2 * x, i));
			m[2 * x] = i;
		}
		if(m.find(x + 1) == m.end() || m[x + 1] > i + 1){
			q.push(make_pair(x + 1, i + 1));
			m[x + 1] = i + 1;
		}
		if(x > 0 && (m.find(x - 1) == m.end() || m[x - 1] > i + 1)){
			q.push(make_pair(x - 1, i + 1));
			m[x - 1] = i + 1;
		}
	}
	return 0;
}
