#include <iostream>

using std::cin;
using std::cout;

int main(){
	int t = 0;
	cin >> t;
	for(int i = 0; i < t; ++i){
		int hp = 0, mp = 0, atk = 0, def = 0;
		cin >> hp >> mp >> atk >> def;
		int nhp = 0, nmp = 0, natk = 0, ndef = 0;
		cin >> nhp >> nmp >> natk >> ndef;
		hp += nhp;
		mp += nmp;
		atk += natk;
		def += ndef;
		if(hp < 1)
			hp = 1;
		if(mp < 1)
			mp = 1;
		if(atk < 0)
			atk = 0;
		cout << hp + 5 * mp + 2 * atk + 2 * def << "\n";
	}
	return 0;
}
