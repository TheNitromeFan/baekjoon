#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int sum1 = 0;
	for(int i = 0; i < n; i += 2){
		sum1 += v[i + 1] - v[i];
	}
	int sum2 = 24 - (v.back() - v.front());
	for(int i = 1; i < n - 1; i += 2){
		sum2 += v[i + 1] - v[i];
	}
	cout << min(sum1, sum2);
	return 0;
}
