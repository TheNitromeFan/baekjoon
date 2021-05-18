#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long k;
	cin >> k;
	cout << 4 * k * k * k * k + 8 * k * k * k + 5 * k * k + k;
	return 0;
}
