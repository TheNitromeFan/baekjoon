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
		int n;
		cin >> n;
		vector<int> p(n);
		for(int i = 0; i < n; ++i){
			cin >> p[i];
		}
		sort(p.begin(), p.end(), greater<int>());
		int discount = 0;
		for(int i = 2; i < n; i += 3){
			discount += p[i];
		}
		cout << discount << '\n';
	}
	return 0;
}
