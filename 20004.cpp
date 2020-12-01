#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a;
	cin >> a;
	for(int n = 1; n <= a; ++n){
		if(30 % (n + 1) == 0){
			cout << n << "\n";
		}
	}
	return 0;
}
