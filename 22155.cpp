#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int branch, cycle;
		cin >> branch >> cycle;
		cout << ((branch <= 1 && cycle <= 2) || (branch <= 2 && cycle <= 1) ? "Yes\n" : "No\n");
	}
	return 0;
}
