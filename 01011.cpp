#include <iostream>
#include <cmath>


using std::cin;
using std::cout;

static int teleports(int current, int goal){
	int distance = goal - current;
	int n = static_cast<int>(floor(sqrt(distance)));
	if(distance - n*n == 0)
		return 2*n - 1;
	else if(distance - n*n <= n)
		return 2*n;
	else
		return 2*n + 1;
}

int main(){
	unsigned tests = 0U;
	int x = 0, y = 0;
	cin >> tests;
	for(unsigned t = 0U; t < tests; ++t){
		cin >> x >> y;
		cout << teleports(x, y) << '\n';
	}
	return 0;
}
