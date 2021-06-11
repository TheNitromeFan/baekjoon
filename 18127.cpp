#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long a, n;
	cin >> a >> n;
	cout << (a - 2) * (n + 1) * (n + 2) / 2 - (a - 3) * (n + 1);
	return 0;
}
