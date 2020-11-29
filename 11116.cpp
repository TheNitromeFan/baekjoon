#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int n;
		cin >> n;
		vector<int> left, right;
		queue<int> q;
		for(int j = 0; j < n; ++j){
			int x;
			cin >> x;
			if(!q.empty() && q.front() == x - 500){
				left.push_back(q.front());
				q.pop();
			}else{
				q.push(x);
			}
		}
		for(int j = 0; j < n; ++j){
			int x;
			cin >> x;
			if(!q.empty() && q.front() == x - 500){
				right.push_back(q.front());
				q.pop();
			}else{
				q.push(x);
			}
		}
		int cnt = 0;
		for(int x : left){
			for(int y : right){
				if(x + 1000 == y){
					++cnt;
					break;
				}else if(x - 1000 == y){
					break;
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}
