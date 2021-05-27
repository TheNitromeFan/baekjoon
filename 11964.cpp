#include <iostream>
#include <queue>
#define MAX 5000001

using namespace std;

int fullest(int t, int a, int b){
	queue<int> q;
	bool visited[MAX][2] = {};
	q.push(a);
	q.push(0);
	visited[a][0] = true;
	q.push(b);
	q.push(0);
	visited[b][0] = true;
	int ans = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		int n = q.front();
		q.pop();
		if(ans < u){
			ans = u;
		}
		if(u + a <= t && !visited[u + a][n]){
			q.push(u + a);
			q.push(n);
			visited[u + a][n] = true;
		}
		if(u + b <= t && !visited[u + b][n]){
			q.push(u + b);
			q.push(n);
			visited[u + b][n] = true;
		}
		if(n == 0 && !visited[u / 2][1]){
			q.push(u / 2);
			q.push(1);
			visited[u / 2][1] = true;
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, a, b;
	cin >> t >> a >> b;
	cout << fullest(t, a, b);
	return 0;
}
