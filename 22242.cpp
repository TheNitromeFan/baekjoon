#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	getline(cin, s);
	int x = 0, y = 0;
	unsigned i = 0;
	while(i < s.length()){
		if(s[i] == 'n' || s[i] == 's' || s[i] == 'e' || s[i] == 'w'){
			unsigned j = i + 1;
			int d = 0;
			while(j < s.length() && s[j] >= '0' && s[j] <= '9'){
				d = 10 * d + s[j] - '0';
				++j;
			}
			if(s[i] == 'n'){
				y += d;
			}else if(s[i] == 's'){
				y -= d;
			}else if(s[i] == 'e'){
				x += d;
			}else{
				x -= d;
			}
			i = j;
		}else{
			++i;
		}
	}
	cout << fixed << setprecision(2) << sqrt(x * x + y * y) << '\n';
	return 0;
}
