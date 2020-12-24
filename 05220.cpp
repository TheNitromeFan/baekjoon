#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int bits, check;
		cin >> bits >> check;
		int cnt = 0;
		for(int j = 0; j < 16; ++j){
			if(bits % 2 == 1){
				++cnt;
			}
			bits /= 2;
		}
		cout << (cnt % 2 == check ? "Valid" : "Corrupt") << "\n";
	}
	return 0;
}
