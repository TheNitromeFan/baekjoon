#include <iostream>
#include <string>

using namespace std;

int ducks(string &quack){
	int q = 0, u = 0, a = 0, ck = 0;
	int ret = 0;
	for(char c : quack){
		switch(c){
			case 'q':
				++q;
				if(ret < q + u + a + ck){
					ret = q + u + a + ck;
				}
				break;
			case 'u':
				if(q == 0){
					return -1;
				}
				--q;
				++u;
				break;
			case 'a':
				if(u == 0){
					return -1;
				}
				--u;
				++a;
				break;
			case 'c':
				if(a == 0){
					return -1;
				}
				--a;
				++ck;
				break;
			case 'k':
				if(ck == 0){
					return -1;
				}
				--ck;
				break;
		}
	}
	if(q != 0 || u != 0 || a != 0 || ck != 0){
		return -1;
	}
	return ret;
}

int main(){
	string quack;
	cin >> quack;
	cout << ducks(quack);
	return 0;
}
