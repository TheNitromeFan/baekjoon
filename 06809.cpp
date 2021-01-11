#include <iostream>
#include <string>
#include <map>

using namespace std;

int cycles(map<char, char> &m, char c){
	char d = c;
	int ret = 0;
	do{
		d = m[d];
		++ret;
	}while(d != c);
	return ret;
}

void encrypt(map<char, char> &m, string &t, int n){
	for(char &c : t){
		int k = n % cycles(m, c);
		for(int i = 0; i < k; ++i){
			c = m[c];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	map<char, char> m;
	for(char c = 'A'; c <= 'Z'; ++c){
		cin >> m[c];
	}
	cin >> m['_'];
	int n;
	cin >> n;
	string t;
	cin >> t;
	encrypt(m, t, n);
	cout << t;
	return 0;
}
