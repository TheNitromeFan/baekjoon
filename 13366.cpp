#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		string x;
		cin >> x;
		int sum = 0;
		for(char c : x){
			sum += c - '0';
		}
		cout << (sum % 9 == 0 ? "YES" : "NO") << "\n";
	}
	return 0;
}
