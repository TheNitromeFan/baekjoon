#include <iostream>

using namespace std;

bool red(int a, int b){
	if(a % b == 0){
		return a / b % 2 == 1;
	}else if(a / b % 2 == 0){
		return red(b, a % b);
	}else{
		return !red(b, a % b);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int z;
	cin >> z;
	for(int i = 0; i < z; ++i){
		int a, b;
		char c;
		cin >> a >> c >> b;
		cout << (red(a, b) ? "czerwony" : "niebieski") << "\n";
	}
	return 0;
}
