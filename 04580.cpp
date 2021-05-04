#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int k;
		cin >> k;
		if(k == 0){
			break;
		}
		int prev = 0;
		for(int i = 1; i <= k; ++i){
			int cur;
			cin >> cur;
			while(prev < cur){
				cout << i << ' ';
				++prev;
			}
		}
		cout << '\n';
	}
	return 0;
}
