#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int p, a, b, c, d;
	cin >> a >> b >> c >> d >> p;
	cout << min(p * a, (p < c) ? b : b + (p - c) * d);
	return 0;
}
