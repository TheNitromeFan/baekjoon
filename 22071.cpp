#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n, l;
		cin >> n >> l;
		vector<int> a(n), b(n);
		for(int i = 0; i < n; ++i){
			cin >> a[i];
		}
		for(int i = 0; i < n; ++i){
			cin >> b[i];
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end(), greater<int>());
		int a_sum = 0, b_sum = 0;
		for(int i = 0; i < l; ++i){
			a_sum += a[i];
			b_sum += b[i];
		}
		cout << (a_sum > b_sum ? "YES\n" : "NO\n");
	}
	return 0;
}
