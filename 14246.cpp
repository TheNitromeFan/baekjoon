#include <iostream>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<long long> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	long long k;
	cin >> k;
	long long cnt = 0;
	int i = 0, j = 0;
	long long sum = v[0];
	while(j < n){
		while(j < n && sum <= k){
			++j;
			sum += v[j];
		}
		cnt += n - j;
		sum -= v[i];
		++i;
	}
	cout << cnt;
	return 0;
}
