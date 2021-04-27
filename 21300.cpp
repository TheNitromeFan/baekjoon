#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int b, m, p, c, s, w;
	cin >> b >> m >> p >> c >> s >> w;
	cout << 5 * (b + m + p + c + s + w);
	return 0;
}
