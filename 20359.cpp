#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int p = 0;
	while(n % 2 == 0){
		n /= 2;
		++p;
	}
	cout << n << ' ' << p;
	return 0;
}
