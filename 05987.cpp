#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int a0 = 0; a0 < n; ++a0){
		int ni, ci;
		string stri;
		cin >> ni >> ci >> stri;
		for(int j = 0; j < ci; ++j){
			string f = stri.substr(ni);
			stri = f + stri;
		}
		cout << stri << '\n';
	}
	return 0;
}
