#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a = 1, b = 1;
	int cnt = 0;
	while(n > b - 1){
		int c = a;
		a = b;
		b += c;
		++cnt;
	}
	cout << cnt;
	return 0;
}
