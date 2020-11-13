#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::max;

int main(){
	int price = 0, n = 0, money = 0;
	cin >> price >> n >> money;
	cout << max(price * n - money, 0);
	return 0;
}
