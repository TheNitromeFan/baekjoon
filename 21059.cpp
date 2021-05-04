#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string a, b;
	cin >> a >> b;
	unsigned x = a.length() / 3, y = b.length() / 3;
	unsigned z = x * y;
	for(unsigned i = 0; i < z; ++i){
		cout << "S(";
	}
	cout << 0;
	for(unsigned i = 0; i < z; ++i){
		cout << ")";
	}
	return 0;
}
