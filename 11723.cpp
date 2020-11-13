#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int m;
	cin >> m;
	bool a[21] = {};
	for(int i = 0; i < m; ++i){
		string action;
		cin >> action;
		int n;
		if(action == "add"){
			cin >> n;
			a[n] = true;
		}else if(action == "remove"){
			cin >> n;
			a[n] = false;
		}else if(action == "check"){
			cin >> n;
			cout << a[n] << '\n';
		}else if(action == "toggle"){
			cin >> n;
			a[n] = !a[n];
		}else if(action == "all"){
			for(int j = 1; j <= 20; ++j){
				a[j] = true;
			}
		}else if(action == "empty"){
			for(int j = 1; j <= 20; ++j){
				a[j] = false;
			}
		}
	}
	return 0;
}
