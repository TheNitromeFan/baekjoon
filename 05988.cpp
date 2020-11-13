#include <iostream>
#include <string>

using namespace std;

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		string s;
		cin >> s;
		if((s[s.length()-1] - '0') % 2){
			cout << "odd" << '\n';
		}else{
			cout << "even" << '\n';
		}
	}
	return 0;
}
