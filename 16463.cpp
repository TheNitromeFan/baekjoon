#include <iostream>

using namespace std;

bool leap(int y){
	return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int weekday = 0;
	int days[12] = {31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
	int ans = 0;
	for(int year = 2019; year <= n; ++year){
		for(int month = 0; month < 12; ++month){
			weekday += days[month];
			if(month == 2 && leap(year)){
				++weekday;
			}
			weekday %= 7;
			if(weekday == 1){
				++ans;
			}
		}
	}
	cout << ans;
	return 0;
}
