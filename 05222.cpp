#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for(int a0 = 0; a0 < t; ++a0){
		string keyword, plaintext;
		cin >> keyword >> plaintext;
		cout << "Ciphertext: ";
		for(unsigned i = 0; i < plaintext.length(); ++i){
			int val = plaintext[i] + keyword[i % keyword.length()] - 'A';
			if(val > 'Z'){
				val -= 26;
			}
			cout << (char)val;
		}
		cout << "\n";
	}
	return 0;
}
