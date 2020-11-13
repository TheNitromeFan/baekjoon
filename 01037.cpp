#include <iostream>
#include <algorithm>


using std::cin;
using std::cout;
using std::sort;

static int n(size_t d, int divisors[50]){
	sort(divisors, divisors+d);
	return divisors[0] * divisors[d-1];
}

int main(){
	size_t d = 0;
	int a[50] = {};
	cin >> d;
	for(size_t i = 0; i < d; ++i)
		cin >> a[i];
	cout << n(d, a);
	return 0;
}
