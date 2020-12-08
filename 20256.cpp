#include <iostream>
#include <cmath>

using namespace std;

bool rightCoupled(int x){
	for(int a = (int)sqrt(x / 2.0) - 1; a * a <= x; ++a){
		if(2 * a * a >= x && x % a == 0){
			return true;
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		cout << rightCoupled(x) << '\n';
	}
	return 0;
}
