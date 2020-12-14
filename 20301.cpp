#include <iostream>
#include <deque>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, m;
	cin >> n >> k >> m;
	deque<int> dq;
	for(int i = 1; i <= n; ++i){
		dq.push_back(i);
	}
	int dir = 1;
	int cnt = 0;
	while(!dq.empty()){
		if(dir > 0){
			for(int j = 1; j < k; ++j){
				dq.push_back(dq.front());
				dq.pop_front();
			}
			cout << dq.front() << '\n';
			dq.pop_front();
		}else{
			for(int j = 1; j < k; ++j){
				dq.push_front(dq.back());
				dq.pop_back();
			}
			cout << dq.back() << '\n';
			dq.pop_back();
		}
		++cnt;
		if(cnt % m == 0){
			dir *= -1;
		}
	}
	return 0;
}
