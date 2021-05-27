#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long red_paint, yellow_paint, blue_paint;
	cin >> red_paint >> yellow_paint >> blue_paint;
	red_paint *= 2;
	yellow_paint *= 2;
	blue_paint *= 2;
	long long yellow, green, blue, purple, red, orange;
	cin >> yellow >> green >> blue >> purple >> red >> orange;
	yellow *= 2;
	green *= 2;
	blue *= 2;
	purple *= 2;
	red *= 2;
	orange *= 2;
	long long red_need = max(0LL, red + purple / 2 + orange / 2 - red_paint);
	long long yellow_need = max(0LL, yellow + green / 2 + orange / 2 - yellow_paint);
	long long blue_need = max(0LL, blue + green / 2 + purple / 2 - blue_paint);
	if(red_need % 2 == 0){
		cout << red_need / 2 << ' ';
	}else{
		cout << fixed << setprecision(1) << red_need / 2.0 << ' ';
	}
	if(yellow_need % 2 == 0){
		cout << yellow_need / 2 << ' ';
	}else{
		cout << fixed << setprecision(1) << yellow_need / 2.0 << ' ';
	}
	if(blue_need % 2 == 0){
		cout << blue_need / 2;
	}else{
		cout << fixed << setprecision(1) << blue_need / 2.0;
	}
	return 0;
}
