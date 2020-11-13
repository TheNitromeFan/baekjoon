#include <iostream>

using namespace std;

int main(){
	int x;
	cin >> x;
	int cnt = 0;
	while(x){
		cnt += (x % 2);
		x /= 2;
	}
	cout << cnt;
	return 0;
}
