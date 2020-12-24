#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		int r, c;
		cin >> r >> c;
		int even = 0, odd = 0;
		for(int i = 0; i < r; ++i){
			for(int j = 0; j < c; ++j){
				int x;
				cin >> x;
				if((i + j) % 2){
					odd += x;
				}else{
					even += x;
				}
			}
		}
		cout << (even == odd ? "YES" : "NO") << "\n";
	}
	return 0;
}
