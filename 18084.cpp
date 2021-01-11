#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

bool win(vector<double> times, double target){
	sort(times.begin(), times.end());
	return times[1] + times[2] + times[3] <= 3 * target;
}

void c(vector<double> &times, double target){
	sort(times.begin(), times.end());
	if(times[0] + times[1] + times[2] > 3 * target){
		cout << "impossible";
		return;
	}else if(times[1] + times[2] + times[3] <= 3 * target){
		cout << "infinite";
		return;
	}
	double low = -1, high = 100;
	for(int i = 0; i < 1000; ++i){
		double mid = (low + high) / 2;
		times.push_back(mid);
		if(win(times, target)){
			low = mid;
		}else{
			high = mid;
		}
		times.pop_back();
	}
	cout << setprecision(2) << fixed << low;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<double> times(4);
	for(int i = 0; i < 4; ++i){
		cin >> times[i];
	}
	double target;
	cin >> target;
	c(times, target);
	return 0;
}
