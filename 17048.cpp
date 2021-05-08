#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	for(int i = 0; i < n; ++i){
		cin >> b[i];
	}
	vector<int> c(n);
	for(int i = 0; i < n; ++i){
		c[i] = b[i] - a[i];
	}
	int ans = 0;
	unordered_map<int, int> m;
	for(int i = 0; i < n; ++i){
		++m[c[i]];
		if(ans < m[c[i]]){
			ans = m[c[i]];
		}
	}
	cout << ans;
	return 0;
}
