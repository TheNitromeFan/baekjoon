#include <iostream>
#include <limits>
#include <string>

using namespace std;

int main(){
	int i = 10;
	int j, k;
	j = k = i++;
	cout << j << ' ' << k;
	return 0;
}
