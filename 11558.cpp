#include <iostream>
#include <vector>

using namespace std;

int call(vector<int> &point, int n){
	if(n == 1){
		return 1;
	}
	vector<bool> visited(n + 1);
	visited[1] = true;
	int ret = 0;
	int cur = 1;
	while(true){
		++ret;
		cur = point[cur];
		if(cur == n){
			return ret;
		}else if(visited[cur]){
			break;
		}
		visited[cur] = true;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		cin >> n;
		vector<int> point(n + 1);
		for(int i = 1; i <= n; ++i){
			cin >> point[i];
		}
		cout << call(point, n) << "\n";
	}
	return 0;
}
