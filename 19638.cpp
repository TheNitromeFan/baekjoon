#include <iostream>
#include <queue>

using namespace std;

int hammer(priority_queue<int> &pq, int hmax, int t){
	for(int i = 0; i < t; ++i){
		int h = pq.top();
		if(h < hmax){
			return i;
		}
		pq.pop();
		if(h > 1){
			pq.push(h / 2);
		}else{
			pq.push(1);
		}
	}
	if(pq.top() < hmax){
		return t;
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, hmax, t;
	cin >> n >> hmax >> t;
	priority_queue<int> pq;
	for(int i = 0; i < n; ++i){
		int h;
		cin >> h;
		pq.push(h);
	}
	int ans = hammer(pq, hmax, t);
	if(ans != -1){
		cout << "YES" << '\n' << ans;
	}else{
		cout << "NO" << '\n' << pq.top();
	}
	return 0;
}
