#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	cout << (n % 2 == 0 || m % 2 == 0 ? 'A' : 'B');
	return 0;
}