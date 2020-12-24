#include <iostream>
#include <queue>

using namespace std;

int last_to_pick(int n, int m){
	queue<int> q;
	for(int i = 1; i <= n; ++i){
		q.push(i);
	}
	while(q.size() > 1){
		for(int j = 0; j < m - 1; ++j){
			q.push(q.front());
			q.pop();
		}
		q.pop();
	}
	return q.front();
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n, m;
		cin >> n >> m;
		if(n == 0 && m == 0){
			break;
		}
		cout << last_to_pick(n, m) << '\n';
	}
	return 0;
}
