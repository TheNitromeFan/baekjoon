#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tc;
	cin >> tc;
	for(int a0 = 1; a0 <= tc; ++a0){
		int l, n, c;
		long long t;
		cin >> l >> t >> n >> c;
		vector<long long> a(c);
		for(int i = 0; i < c; ++i){
			cin >> a[i];
		}
		vector<long long> time(n);
		for(int j = 0; j < n; ++j){
			time[j] = a[j % c] * 2;
		}
		priority_queue<long long> pq;
		long long time_sum = 0;
		int i = 0;
		while(i < n){
			if(t - time[i] < 0){
				time_sum += t;
				pq.push(time[i] - t);
				++i;
				while(i < n){
					pq.push(time[i]);
					++i;
				}
			}else{
				time_sum += time[i];
				t -= time[i];
				++i;
			}
		}
		while(!pq.empty()){
			if(l > 0){
				time_sum += pq.top() / 2;
				--l;
			}else{
				time_sum += pq.top();
			}
			pq.pop();
		}
		cout << "Case #" << a0 << ": "  << time_sum << "\n";
	}
	return 0;
}
