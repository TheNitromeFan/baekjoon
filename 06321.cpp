#include <iostream>
#include <string>

using namespace std;

void print_next(string &s){
	for(int i = 0; i < s.length(); ++i){
		char next;
		if(s[i] == 'Z'){
			next = 'A';
		}else{
			next = s[i] + 1;
		}
		cout << next;
	}
}

int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i){
		string s;
		cin >> s;
		cout << "String #" << i << '\n';
		print_next(s);
		cout << "\n\n";
	}
	return 0;
}
