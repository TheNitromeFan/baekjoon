#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int cnt = 0;
	while(true){
		++cnt;
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		vector<string> names(n, "");
		for(int i = 0; i < n; ++i){
			cin >> names[i];
		}
		cout << "SET " << cnt << '\n';
		for(int i = 0; i < n; i += 2){
			cout << names[i] << '\n';
		}
		for(int i = (n % 2) ? n - 2 : n - 1; i > 0; i -= 2){
			cout << names[i] << '\n';
		}
	}
	return 0;
}
