#include <iostream>

using namespace std;

int main(){
	int cnt = 0;
	while(true){
		++cnt;
		int opt, w;
		cin >> opt >> w;
		if(opt == 0 && w == 0){
			break;
		}
		int weight = w;
		bool dead = false;
		while(true){
			char c;
			int n;
			cin >> c >> n;
			if(c == '#' && n == 0){
				break;
			}
			if(c == 'E'){
				weight -= n;
				if(weight <= 0){
					dead = true;
				}
			}else{
				weight += n;
			}
		}
		cout << cnt << ' ';
		if(dead){
			cout << "RIP\n";
		}else{
			cout << (2 * weight > opt && weight < 2 * opt ? ":-)\n" : ":-(\n");
		}
	}
	return 0;
}
