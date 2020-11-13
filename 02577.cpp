#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(){
	int a = 0, b = 0, c = 0;
	cin >> a >> b >> c;
	int product = a * b * c;
	vector<int> v(10, 0);
	while(product > 0){
		++v[product % 10];
		product /= 10;
	}
	for(int x : v)
		cout << x << endl;
	return 0;
}
