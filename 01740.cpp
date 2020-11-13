#include <iostream>

using namespace std;

int main(){
	long long n;
	cin >> n;
	long long answer = 0;
	long long power_of_3 = 1;
	while(n > 0){
		if(n % 2 == 1){
			answer += power_of_3;
		}
		n /= 2;
		power_of_3 *= 3;
	}
	cout << answer << endl;
	return 0;
}
