#include <iostream>
#include <string>

using namespace std;

int names[26];

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		string name;
		cin >> name;
		++names[name[0] - 'a'];
	}
	string ans;
	for(int i = 0; i < 26; ++i){
		if(names[i] >= 5){
			ans += i + 'a';
		}
	}
	cout << (ans.length() ? ans : "PREDAJA");
	return 0;
}
