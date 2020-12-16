#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int n;
		cin >> n;
		int evens = 0, odds = 0;
		for(int i = 0; i < n; ++i){
			int x;
			cin >> x;
			if(x > 0 && i % 2 == 0){
				++evens;
			}else if(x > 0){
				++odds;
			}
		}
		cout << (n % 2 == 1 || (evens - odds >= -1 && evens - odds <= 1) ? "YES" : "NO") << "\n";
	}
	return 0;
}
