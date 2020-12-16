#include <iostream>
#include <cmath>

using namespace std;

void difference_of_two_squares(int n){
	int x = (int)sqrt(n);
	for(; x >= 1; --x){
		if(n % x == 0 && x % 2 == n / x % 2){
			cout << (n / x - x) / 2 << " " << (n / x + x) / 2 << "\n";
			return;
		}
	}
	cout << "IMPOSSIBLE\n";
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int n;
		cin >> n;
		difference_of_two_squares(n);
	}
	return 0;
}
