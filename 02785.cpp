#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	deque<int> dq;
	for(int i = 0; i < n; ++i){
		int len;
		cin >> len;
		dq.push_back(len);
	}
	sort(dq.begin(), dq.end());
	int cnt = 0;
	while(dq.size() > 1){
		int x = dq.back();
		dq.pop_back();
		dq.back() += x;
		--dq.front();
		if(dq.front() == 0){
			dq.pop_front();
		}
		++cnt;
	}
	cout << cnt;
	return 0;
}
