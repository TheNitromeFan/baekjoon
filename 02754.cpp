#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string grade;
	cin >> grade;
	if(grade == "F"){
		cout << "0.0";
		return 0;
	}
	double ans;
	switch(grade[0]){
		case 'A':
			ans = 4;
			break;
		case 'B':
			ans = 3;
			break;
		case 'C':
			ans = 2;
			break;
		case 'D':
			ans = 1;
			break;
	}
	switch(grade[1]){
		case '+':
			ans += 0.3;
			break;
		case '-':
			ans -= 0.3;
			break;
	}
	cout << fixed << setprecision(1) << ans;
	return 0;
}
