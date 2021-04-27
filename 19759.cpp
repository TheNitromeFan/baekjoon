#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a[25] = {100, 200, 400, 800, 1600, 3200, 6400, 13000, 26000, 52000,
				104000, 208000, 416000, 832000, 1670000, 3340000, 6680000,
				13360000, 26720000, 53440000, 106900000, 213800000, 427600000,
				855200000, 1710400000};
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		cout << a[i] << '\n';
	}
	return 0;
}
