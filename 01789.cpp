#include <iostream>
#include <cmath>

using namespace std;

int main(){
	long long s;
	cin >> s;
	cout << (int)((sqrt((double)(1 + 8 * s)) - 1) / 2) << endl;
	return 0;
}
