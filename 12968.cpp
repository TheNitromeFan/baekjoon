#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int r, c, k;
	cin >> r >> c >> k;
	cout << (r % 2 == 0 || c % 2 == 0 || k == 1);
	return 0;
}
