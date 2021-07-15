#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k;
	cin >> k;
	int pow2 = 1;
	while(pow2 < k){
		pow2 *= 2;
	}
	cout << pow2 << ' ';
	int cnt = 0;
	while(k % pow2 != 0){
		++cnt;
		pow2 /= 2;
	}
	cout << cnt << '\n';
	return 0;
}
