#include <iostream>
#include <string>

using namespace std;

int main(){
	string n;
	cin >> n;
	int sum1 = 0, sum2 = 0;
	for(unsigned i = 0, j = n.length() - 1; i < j; ++i, --j){
		sum1 += n[i] - '0';
		sum2 += n[j] - '0';
	}
	cout << (sum1 == sum2 ? "LUCKY" : "READY");
	return 0;
}
