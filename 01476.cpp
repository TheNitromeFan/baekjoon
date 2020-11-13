#include <iostream>

using namespace std;

int main(){
	int e, s, m;
	cin >> e >> s >> m;
	cout << (13 * 28 * 19 * e + 15 * 17 * 19 * s + 15 * 28 * 10 * m - 1) % (15 * 28 * 19) + 1 << endl;
	return 0;
}
