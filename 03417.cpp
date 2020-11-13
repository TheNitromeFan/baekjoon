#include <iostream>
#include <string>

using namespace std;

char encrypt(char a, char b){
	char ret = (a - 'A') + b + 1;
	if(ret > 'Z'){
		ret -= 26;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		string k, p;
		cin >> k;
		if(k == "0"){
			break;
		}
		cin >> p;
		for(unsigned i = 0; i < p.length(); ++i){
			cout << encrypt(p[i], k[i % k.length()]);
		}
		cout << '\n';
	}
	return 0;
}
