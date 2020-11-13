#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string fenrir;
	cin >> fenrir;
	unsigned len = fenrir.length();
	for(unsigned i = 0; i < len - 2; ++i){
		cout << 'A';
	}
	cout << "WHO";
	return 0;
}
