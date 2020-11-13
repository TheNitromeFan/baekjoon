#include <iostream>
#include <algorithm>


using std::cin;
using std::cout;
using std::sort;

static int minimal_sum(size_t size, int a[50], int b[50]){
	sort(a, a+size);
	sort(b, b+size);
	int ret = 0;
	for(size_t i = 0; i < size; ++i)
		ret += a[size-1-i] * b[i];
	return ret;
}

int main(){
	size_t n;
	int a[50], b[50];
	cin >> n;
	for(size_t i = 0; i < n; ++i)
		cin >> a[i];
	for(size_t i = 0; i < n; ++i)
		cin >> b[i];
	cout << minimal_sum(n, a, b);
	return 0;
}
