#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string ssn;
	cin >> ssn;
	if(ssn[6] == '+' && ssn[0] >= '4'){
		cout << "18" << ssn.substr(0, 6) << ssn.substr(7, 4);
	}else if(ssn[6] == '-' && ssn[0] <= '1'){
		cout << "20" << ssn.substr(0, 6) << ssn.substr(7, 4);
	}else{
		cout << "19" << ssn.substr(0, 6) << ssn.substr(7, 4);
	}
	return 0;
}
