#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, c;
	cin >> a >> b >> c;
	cout << 3 * max(max(a, b), c) - a - b - c << '\n';
	return 0;
}
