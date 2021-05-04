#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n / 2; ++i){
		cout << 1 << ' ' << 2 << ' ';
	}
	if(n % 2 == 1){
		cout << 3;
	}
	return 0;
}
