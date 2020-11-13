#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int a, b, v;
	cin >> a >> b >> v;
	int n = (v - b) / (a - b);
	cout << ((n * (a - b) == v - b) ? n : n+1) << endl;
	return 0;
}
