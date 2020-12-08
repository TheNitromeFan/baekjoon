#include <iostream>
#include <string>

using namespace std;

void find_pos(string s, unsigned &level, unsigned &x, unsigned &y){
	level = s.length();
	x = 0;
	y = 0;
	for(unsigned i = 0; i < level; ++i){
		if(s[i] == '1' || s[i] == '3'){
			x += (1U << (level - 1 - i));
		}
		if(s[i] == '2' || s[i] == '3'){
			y += (1U << (level - 1 - i));
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	unsigned level = 0, x = 0, y = 0;
	find_pos(s, level, x, y);
	cout << level << ' ' << x << ' ' << y;
	return 0;
}
