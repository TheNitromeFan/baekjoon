#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int n;
		cin >> n;
		int left, right;
		bool eaten = false;
		for(int j = 0; j < n; ++j){
			cin >> left >> right;
			if(n != left + right){
				eaten = true;
			}
		}
		cout << (eaten ? "yes\n" : "no\n");
	}
	return 0;
}
