#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int ad, cd, ed, an, cn, en;
	cin >> ad >> cd >> ed >> an >> cn >> en;
	if(an == ad && cn == cd && en == ed){
		cout << 'A';
	}else if(2 * an >= ad && cn == cd && en == ed){
		cout << 'B';
	}else if(cn == cd && en == ed){
		cout << 'C';
	}else if(2 * cn >= cd && en == ed){
		cout << 'D';
	}else{
		cout << 'E';
	}
	return 0;
}
