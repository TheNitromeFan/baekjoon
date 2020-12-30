#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string a, b;
	while(getline(cin, a) && getline(cin, b)){
		map<char, int> cntr1, cntr2;
		for(char c : a){
			++cntr1[c];
		}
		for(char c : b){
			++cntr2[c];
		}
		for(char c = 'a'; c <= 'z'; ++c){
			int v = min(cntr1[c], cntr2[c]);
			for(int i = 0; i < v; ++i){
				cout << c;
			}
		}
		cout << '\n';
	}
	return 0;
}
