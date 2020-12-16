#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int visit(vector<int> &v, int n, vector<bool> &visited, int s){
	queue<int> q;
	q.push(s);
	visited[s] = true;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		if(x - v[x] >= 1 && !visited[x - v[x]]){
			q.push(x - v[x]);
			visited[x - v[x]] = true;
		}
		if(x + v[x] <= n && !visited[x + v[x]]){
			q.push(x + v[x]);
			visited[x + v[x]] = true;
		}
	}
	int cnt = 0;
	for(int i = 1; i <= n; ++i){
		if(visited[i]){
			++cnt;
		}
	}
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for(int i = 1; i <= n; ++i){
		cin >> v[i];
	}
	int s;
	cin >> s;
	vector<bool> visited(n + 1);
	cout << visit(v, n, visited, s);
	return 0;
}
