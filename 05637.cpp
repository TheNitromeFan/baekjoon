#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string ans;
	string word;
	cin >> word;
	do{
		string cmp;
		for(char c : word){
			if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '-'){
				cmp += c;
			}
		}
		if(cmp.length() > ans.length()){
			ans = cmp;
		}
		cin >> word;
	}while(word != "E-N-D");
	for(char c : ans){
		if(c >= 'A' && c <= 'Z'){
			c += 'a' - 'A';
		}
		cout << c;
	}
	return 0;
}
