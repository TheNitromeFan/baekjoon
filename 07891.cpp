#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int x, y;
		cin >> x >> y;
		cout << x + y << '\n';
	}
	return 0;
}
