#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int i = 0; i < t; ++i){
		long long a, b;
		cin >> a >> b;
		long long c = a + b;
		cout << c * c * (c - 1) / 2 << '\n';
	}
	return 0;
}
