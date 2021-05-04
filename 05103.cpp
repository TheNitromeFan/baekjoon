#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		string dvd;
		cin >> dvd;
		if(dvd == "#"){
			break;
		}
		int m, s;
		cin >> m >> s;
		int t;
		cin >> t;
		for(int i = 0; i < t; ++i){
			char trans;
			int stock;
			cin >> trans >> stock;
			if(trans == 'R'){
				s += stock;
				if(s > m){
					s = m;
				}
			}else{
				s -= stock;
				if(s < 0){
					s = 0;
				}
			}
		}
		cout << dvd << ' ' << s << '\n';
	}
	return 0;
}
