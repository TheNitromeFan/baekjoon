#include <iostream>
#include <string>

using namespace std;

int main(){
	while(true){
		string a, b, c;
		cin >> a;
		if(a == "#"){
			break;
		}
		cin >> b >> c;
		string ans;
		for(int i = 0; i < a.length(); ++i){
			int tmp = (int)b[i] - a[i] + c[i];
			if(tmp < 'a'){
				tmp += 26;
			}else if(tmp > 'z'){
				tmp -= 26;
			}
			char letter = tmp;
			ans += letter;
		}
		cout << a << ' ' << b << ' ' << c << ' ' << ans << '\n';
	}
	return 0;
}
