#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int set_bits = 0;
	while(n){
		n &= n - 1;
		++set_bits;
	}
	cout << (1 << set_bits) << '\n';
	return 0;
}
