#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x, k, a;
	cin >> x >> k >> a;
	cout << (x % (k + a) < k);
	return 0;
}
