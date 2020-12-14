#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, d;
	cin >> n >> d;
	vector<int> a(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int i = 0, j = 0;
	long long ans = 0;
	while(i < n){
		while(j < n && a[j] / d == a[i] / d){
			++j;
		}
		ans += (long long)(j - i) * (j - i - 1) / 2;
		i = j;
	}
	cout << ans;
	return 0;
}
