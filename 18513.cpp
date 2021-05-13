#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

long long dist(queue<long long> &q, unordered_map<long long, int> &m, int k){
	long long ret = 0;
	int cntr = 0;
	while(!q.empty() && cntr < k){
		long long u = q.front();
		q.pop();
		if(m.find(u + 1) == m.end()){
			q.push(u + 1);
			m[u + 1] = m[u] + 1;
			ret += m[u + 1];
			++cntr;
			if(cntr == k){
				return ret;
			}
		}
		if(m.find(u - 1) == m.end()){
			q.push(u - 1);
			m[u - 1] = m[u] + 1;
			ret += m[u - 1];
			++cntr;
			if(cntr == k){
				return ret;
			}
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	queue<long long> q;
	unordered_map<long long, int> m;
	for(int i = 0; i < n; ++i){
		long long x;
		cin >> x;
		q.push(x);
		m[x] = 0;
	}
	cout << dist(q, m, k);
	return 0;
}
