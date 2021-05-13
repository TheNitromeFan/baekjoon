#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000000000000000000LL

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	cin >> n;
	vector<long long> fibs;
	fibs.push_back(1);
	fibs.push_back(2);
	unsigned idx = 0;
	while(true){
		long long fib = fibs[idx] + fibs[idx + 1];
		if(fib > MAX){
			break;
		}
		fibs.push_back(fib);
		++idx;
	}
	reverse(fibs.begin(), fibs.end());
	vector<long long> ans;
	idx = 0;
	while(n > 0){
		if(fibs[idx] > n){
			++idx;
			continue;
		}
		ans.push_back(fibs[idx]);
		n -= fibs[idx];
		++idx;
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for(long long x : ans){
		cout << x << ' ';
	}
	return 0;
}
