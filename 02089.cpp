#include <iostream>
#include <string>

using namespace std;

int main(){
	int n;
	cin >> n;
	if(n == 0){
		cout << 0;
		return 0;
	}
	string ans;
	while(n != 0){
		int remainder = n % (-2);
		n /= (-2);
		if(remainder < 0){
			remainder += 2;
			n += 1;
		}
		ans = to_string(remainder) + ans;
	}
	cout << ans;
	return 0;
}
