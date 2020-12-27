#include <iostream>
#include <queue>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	priority_queue<int> pq;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		if(x == 0){
			if(pq.empty()){
				cout << -1 << '\n';
			}else{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}else{
			for(int j = 0; j < x; ++j){
				int present;
				cin >> present;
				pq.push(present);
			}
		}
	}
	return 0;
}