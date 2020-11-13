#include <iostream>

using namespace std;

int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int x, y;
		cin >> x >> y;
		if(x < 12 || y < 4){
			cout << -1 << '\n';
			continue;
		}
		cout << 11 * y + 4 << '\n';
	}
	return 0;
}
