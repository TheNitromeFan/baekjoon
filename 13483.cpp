#include <iostream>
#include <tuple>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int d, m, y;
	cin >> d >> m >> y;
	y -= 18;
	tuple<int, int, int> day1 = make_tuple(y, m, d);
	int n;
	cin >> n;
	tuple<int, int, int> birth;
	int king = -1;
	for(int i = 1; i <= n; ++i){
		tuple<int, int, int> day2;
		cin >> get<2>(day2) >> get<1>(day2) >> get<0>(day2);
		if(day2 <= day1 && day2 > birth){
			birth = day2;
			king = i;
		}
	}
	cout << king;
	return 0;
}
