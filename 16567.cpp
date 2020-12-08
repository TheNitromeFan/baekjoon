#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<int> road(n + 2);
	int cnt = 0;
	for(int i = 1; i <= n; ++i){
		cin >> road[i];
		if(road[i] && !road[i - 1]){
			++cnt;
		}
	}
	for(int j = 0; j < m; ++j){
		int order;
		cin >> order;
		if(order){
			int pos;
			cin >> pos;
			if(!road[pos - 1] && !road[pos] && !road[pos + 1]){
				++cnt;
			}else if(road[pos - 1] && !road[pos] && road[pos + 1]){
				--cnt;
			}
			road[pos] = 1;
		}else{
			cout << cnt << '\n';
		}
	}
	return 0;
}
