#include <iostream>
#include <set>

using namespace std;

bool power_of_2(long long n){
	while(n > 1){
		if(n % 2 == 1){
			return false;
		}
		n /= 2;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	cin >> n;
	cout << (power_of_2(n) ? "TAK" : "NIE");
	return 0;
}
