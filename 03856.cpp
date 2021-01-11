#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int n;
		cin >> n;
		if(n == 0){
			break;
		}
		int plates1 = 0, plates2 = 0;
		for(int i = 0; i < n; ++i){
			string command;
			int m;
			cin >> command >> m;
			if(command == "DROP"){
				cout << "DROP 2 " << m << "\n";
				plates2 += m;
			}else{
				if(plates1 < m){
					if(plates1 > 0){
						cout << "TAKE 1 " << plates1 << "\n";
						m -= plates1;
						plates1 = 0;
					}
					cout << "MOVE 2->1 " << plates2 << "\n";
					plates1 = plates2;
					plates2 = 0;
					cout << "TAKE 1 " << m << "\n";
					plates1 -= m;
				}else{
					cout << "TAKE 1 " << m << "\n";
					plates1 -= m;
				}
			}
		}
		cout << "\n";
	}
	return 0;
}
