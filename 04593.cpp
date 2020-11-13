#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		string a, b;
		cin >> a >> b;
		if(a == "E" && b == "E"){
			break;
		}
		int x = 0, y = 0;
		for(unsigned i = 0; i < a.length(); ++i){
			if((a[i] == 'R' && b[i] == 'S') || (a[i] == 'S' && b[i] == 'P') || (a[i] == 'P' && b[i] == 'R')){
				++x;
			}else if((a[i] == 'R' && b[i] == 'P') || (a[i] == 'P' && b[i] == 'S') || (a[i] == 'S' && b[i] == 'R')){
				++y;
			}
		}
		cout << "P1: " << x << '\n' << "P2: " << y << '\n';
	}
	return 0;
}
