#include <iostream>
#include <string>
#define MAX 10

using namespace std;

int letter_to_value(char c){
	if(c == ' '){
		return 36;
	}else if(c >= 'A' && c <= 'Z'){
		return c - 'A';
	}else{
		return c - '0' + 26;
	}
}

char value_to_letter(int v){
	if(v == 36){
		return ' ';
	}else if(v < 26){
		return v + 'A';
	}else{
		return v - 26 + '0';
	}
}

string ciphertext(int a[][MAX], unsigned sz, string plain, unsigned idx){
	string ret = "";
	for(unsigned i = 0; i < sz; ++i){
		int val = 0;
		for(unsigned j = 0; j < sz; ++j){
			val += a[i][j] * letter_to_value(plain[idx + j]);
		}
		ret += value_to_letter(val % 37);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unsigned n;
	cin >> n;
	int a[MAX][MAX];
	for(unsigned i = 0; i < n; ++i){
		for(unsigned j = 0; j < n; ++j){
			cin >> a[i][j];
		}
	}
	string plaintext;
	getline(cin, plaintext);
	getline(cin, plaintext);
	if(plaintext.length() % n != 0){
		plaintext += string(n - plaintext.length() % n, ' ');
	}
	for(unsigned idx = 0; idx < plaintext.length(); idx += n){
		cout << ciphertext(a, n, plaintext, idx);
	}
	return 0;
}
