#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		string route;
		int cap;
		cin >> route >> cap;
		if(route == "#" && cap == 0){
			break;
		}
		int p;
		cin >> p;
		int n;
		cin >> n;
		for(int i = 0; i < n; ++i){
			int in, out;
			cin >> out >> in;
			p -= out;
			p += in;
			if(p > cap){
				p = cap;
			}
		}
		cout << route << ' ' << p << '\n';
	}
	return 0;
}
