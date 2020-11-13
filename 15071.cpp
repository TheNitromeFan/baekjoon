#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string cipher, secret;
	cin >> cipher >> secret;
	for(unsigned i = 0; i < cipher.length(); ++i){
		char ans = cipher[i] - (secret[i] - 'A');
		if(ans < 'A'){
			ans += 26;
		}
		cout << ans;
		secret += ans;
	}
	return 0;
}
