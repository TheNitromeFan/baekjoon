#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for(int a0 = 0; a0 < n; ++a0){
		int k;
		cin >> k;
		string name;
		getline(cin, name);
		getline(cin, name);
		bool peasoup = false, pancakes = false;
		for(int a1 = 0; a1 < k; ++a1){
			string menu;
			getline(cin, menu);
			if(menu == "pea soup"){
				peasoup = true;
			}else if(menu == "pancakes"){
				pancakes = true;
			}
		}
		if(peasoup && pancakes){
			cout << name;
			return 0;
		}
	}
	cout << "Anywhere is fine I guess";
	return 0;
}
