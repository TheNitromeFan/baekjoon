#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
  		b[i] = max(x * a.front(), x * a.back());
	}
	sort(b.begin(), b.end(), greater<int>());
	cout << b[k];
	return 0;
}
