#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int p;
	cin >> p;
	for(int a0 = 1; a0 <= p; ++a0){
		int k, n;
		cin >> k >> n;
		vector<int> a(n);
		for(int i = 0; i < n; ++i){
			cin >> a[i];
		}
		vector<int> b = a;
		sort(b.begin(), b.end());
		int j = 0;
		for(int i = 0; i < n; ++i){
			if(a[i] == b[j]){
				++j;
			}
		}
		cout << k << ' ' << n - j << '\n';
	}
	return 0;
}
