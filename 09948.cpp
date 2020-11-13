#include <iostream>
#include <string>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(true){
		int day;
		string month;
		cin >> day >> month;
		if(day == 0 && month == "#"){
			break;
		}
		if(day == 29 && month == "February"){
			cout << "Unlucky\n";
		}else if(day == 4 && month == "August"){
			cout << "Happy birthday\n";
		}else if(month == "September" || month == "October" || month == "November" || month == "December" || (month == "August" && day > 4)){
			cout << "No\n";
		}else{
			cout << "Yes\n";
		}
	}
	return 0;
}
