#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

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
	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end(), greater<int>());
	long long ans = 1;
	int j = 0;
	for(int i = 0; i < n; ++i){
		while(j < n && b[j] >= a[i]){
			++j;
		}
		ans *= j - i;
	}
	cout << ans;
	return 0;
}
