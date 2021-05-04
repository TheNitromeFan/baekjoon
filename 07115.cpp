#include <iostream>
#include <cmath>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k, r;
	cin >> k >> r;
	int squares = 2 * ((r - 1) / k + 1) - 1;
	for(int x = k; x < r; x += k){
		int y = (int)sqrt(r * r - x * x);
		if(y % k == 0 && x * x + y * y == r * r){
			--squares;
		}
	}
	cout << 4 * squares;
	return 0;
}
