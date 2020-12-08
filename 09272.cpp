#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n1, n2;
	cin >> n1 >> n2;
	cout << (n2 - n1) * (n2 - n1 + 1) / 2;
	return 0;
}
