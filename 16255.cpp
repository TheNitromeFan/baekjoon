#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int k, x, y;
		cin >> k >> x >> y;
		int a = 0, b = 0;
		while(!(x + a >= k && x + a - y >= 2)){
			++a;
		}
		while(!(y + b >= k && y + b - x >= 2)){
			++b;
		}
		cout << min(a, b) << '\n';
	}
	return 0;
}
