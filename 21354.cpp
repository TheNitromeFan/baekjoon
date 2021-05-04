#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a, p;
	cin >> a >> p;
	if(7 * a > 13 * p){
		cout << "Axel";
	}else if(7 * a < 13 * p){
		cout << "Petra";
	}else{
		cout << "lika";
	}
	return 0;
}
