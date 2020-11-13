#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string record;
	cin >> record;
	int a = 0, b = 0;
	int awins = 0, bwins = 0;
	for(char c : record){
		if(c == 'A'){
			++a;
			if(a == 21){
				++awins;
				cout << a << '-' << b << '\n';
				a = 0;
				b = 0;
			}
		}else{
			++b;
			if(b == 21){
				++bwins;
				cout << a << '-' << b << '\n';
				a = 0;
				b = 0;
			}
		}
	}
	cout << (awins > bwins ? 'A' : 'B');
	return 0;
}
