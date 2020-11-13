#include <iostream>
#include <string>

using namespace std;

string base_10_to_9(int n){
	string ans = "";
	while(n > 0){
		ans = to_string(n % 9) + ans;
		n /= 9;
	}
	return ans;
}

int main(){
	int t;
	cin >> t;
	cout << base_10_to_9(t);
	return 0;
}
