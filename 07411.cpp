#include <iostream>
#include <string>
#include <vector>

using namespace std;

int hex_to_dec(char c){
	if(c >= 'A' && c <= 'F'){
		return c - 'A' + 10;
	}else{
		return c - '0';
	}
}

char dec_to_hex(int x){
	if(x >= 10){
		return x - 10 + 'A';
	}else{
		return x + '0';
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string message1, message2;
	cin >> message1 >> message2;
	vector<int> m1, m2, key, original;
	for(unsigned i = 0; i < message1.length(); i += 2){
		m1.push_back(16 * hex_to_dec(message1[i]) + hex_to_dec(message1[i + 1]));
	}
	for(unsigned i = 0; i < message2.length(); i += 2){
		m2.push_back(16 * hex_to_dec(message2[i]) + hex_to_dec(message2[i + 1]));
	}
	key.push_back(32 ^ m2.front());
	for(unsigned i = 0; i < m1.size(); ++i){
		original.push_back(m1[i] ^ key.back());
		key.push_back(m2[i + 1] ^ original.back());
	}
	for(int x : key){
		cout << dec_to_hex(x / 16) << dec_to_hex(x % 16);
	}
	return 0;
}
