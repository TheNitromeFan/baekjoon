#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		string games;
		cin >> games;
		if(games == "#"){
			break;
		}
		int x = 0, y = 0;
		int a = 0, b = 0;
		for(char c : games){
			if(c == 'A'){
				++a;
				if(a >= 4 && a - b >= 2){
					++x;
					a = 0;
					b = 0;
				}
			}else{
				++b;
				if(b >= 4 && b - a >= 2){
					++y;
					a = 0;
					b = 0;
				}
			}
		}
		cout << "A " << x << " B " << y << '\n';
	}
	return 0;
}
