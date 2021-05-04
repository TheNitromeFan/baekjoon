#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int m = 2 * n / 3;
	cout << m - m % 4;
	return 0;
}
