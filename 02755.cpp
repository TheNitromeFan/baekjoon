#include <cmath>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int point(string grade){
	if(grade == "F"){
		return 0;
	}
	int ret = 10;
	switch(grade[0]){
		case 'A':
			ret *= 4;
			break;
		case 'B':
			ret *= 3;
			break;
		case 'C':
			ret *= 2;
			break;
	}
	switch(grade[1]){
		case '+':
			ret += 3;
			break;
		case '-':
			ret -= 3;
			break;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int points = 0, credits = 0;
	for(int i = 0; i < n; ++i){
		string subject, grade;
		int credit;
		cin >> subject >> credit >> grade;
		credits += credit;
		points += point(grade) * credit;
	}
	double ans = points / (double)(credits * 10);
	cout << fixed << setprecision(2) << round(ans * 100) / 100;
	return 0;
}
