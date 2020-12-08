#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a = 0, b = 0, c = 0;
	for(int i = 0; i < n; ++i){
		string s;
		cin >> s;
		if(s == "1/4"){
			++a;
		}else if(s == "1/2"){
			++b;
		}else if(s == "3/4"){
			++c;
		}
	}
	int pizza = 0;
	pizza += c;
	if(a > c){
		a -= c;
	}else{
		a = 0;
	}
	c = 0;
	if(b % 2 == 0){
		pizza += b / 2;
		b = 0;
	}else{
		pizza += (b + 1) / 2;
		if(a > 2){
			a -= 2;
		}else{
			a = 0;
		}
		b = 0;
	}
	if(a % 4 == 0){
		pizza += a / 4;
	}else{
		pizza += (a + 3) / 4;
	}
	a = 0;
	cout << pizza;
	return 0;
}
