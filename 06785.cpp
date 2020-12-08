#include <iostream>

using namespace std;

bool crystal(int mag, int x, int y){
	if(mag == 1){
		return (x == 1 && y == 0) || (x == 2 && y == 0) || (x == 3 && y == 0) || (x == 2 && y == 1);
	}
	return crystal(mag - 1, x / 5, y / 5) ||
	 (y / 5 > 0 && crystal(mag - 1, x / 5, y / 5 - 1) && crystal(1, x % 5, y % 5));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		int m, x, y;
		cin >> m >> x >> y;
		cout << (crystal(m, x, y) ? "crystal" : "empty") << "\n";
	}
	return 0;
}
