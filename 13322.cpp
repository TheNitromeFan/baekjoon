#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	for(unsigned i = 0; i < s.length(); ++i){
		cout << i << '\n';
	}
	return 0;
}
