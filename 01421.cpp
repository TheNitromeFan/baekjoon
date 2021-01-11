#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, c, w;
	cin >> n >> c >> w;
	vector<int> logs(n);
	for(int &log : logs){
		cin >> log;
	}
	long long ans = 0;
	for(int len = 1; len <= 10000; ++len){
		long long revenue = 0;
		for(int log : logs){
			int q = log / len, r = log % len;
			if(r == 0){
				revenue += max(0LL, (long long)q * len * w - (q - 1) * c);
			}else{
				revenue += max(0LL, (long long)q * len * w - q * c);
			}
		}
		ans = max(ans, revenue);
	}
	cout << ans;
	return 0;
}
