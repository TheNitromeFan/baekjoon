#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	if(n % 2 == 0){
		cout << "YES\n1\n";
		for(int i = 1; i <= n; ++i){
			if(i % 2 == 1){
				cout << '+';
			}else{
				cout << '-';
			}
		}
	}else if(n > 1){
		cout << "YES\n3\n-++";
		for(int i = 4; i <= n; ++i){
			if(i % 2 == 0){
				cout << '+';
			}else{
				cout << '-';
			}
		}
	}else{
		cout << "NO";
	}
	return 0;
}
