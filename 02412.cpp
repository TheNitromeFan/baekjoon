#include <iostream>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int bfs(unordered_set<long long> &s, unordered_map<long long, int> &m, int t){
	queue<int> q;
	q.push(0);
	q.push(0);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		int y = q.front();
		q.pop();
		long long p0 = x * 1000000LL + y;
		if(y == t){
			return m[p0];
		}
		for(int nx = x - 2; nx <= x + 2; ++nx){
			for(int ny = y - 2; ny <= y + 2; ++ny){
				long long p = nx * 1000000LL + ny;
				if(s.find(p) != s.end() && m[p] == -1){
					q.push(nx);
					q.push(ny);
					m[p] = m[p0] + 1;
				}
			}
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, t;
	cin >> n >> t;
	unordered_set<long long> s;
	unordered_map<long long, int> m;
	for(int i = 0; i < n; ++i){
		int x, y;
		cin >> x >> y;
		s.insert(x * 1000000LL + y);
		m[x * 1000000LL + y] = -1;
	}
	cout << bfs(s, m, t);
	return 0;
}
