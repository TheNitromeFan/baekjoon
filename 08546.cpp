#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int a = 1, b = 1;
	if(n == 1){
		cout << b;
		++n;
	}
	for(int i = 2; i < n; ++i){
		int tmp = b;
		b = (a + b) % 10;
		a = tmp;
	}
	for(int i = n; i <= m; ++i){
		cout << b;
		int tmp = b;
		b = (a + b) % 10;
		a = tmp;
	}
	return 0;
}
