#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		int odd1 = 0, even2 = 0;
		for(int i = 0; i < n; ++i){
			int x;
			cin >> x;
			if(x % 2 == 1){
				++odd1;
			}
		}
		for(int i = 0; i < n; ++i){
			int x;
			cin >> x;
			if(x % 2 == 0){
				++even2;
			}
		}
		cout << abs(odd1 - even2) << '\n';
	}
	return 0;
}
