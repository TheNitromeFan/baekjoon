#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
	string line;
	cin >> line;
	vector<int> scores;
	for(unsigned idx = 0; idx < line.length(); ++idx){
		if(line[idx] == '1'){
			if(idx + 1 < line.length() && line[idx + 1] == '0'){
				scores.push_back(10);
				++idx;
			}else{
				scores.push_back(1);
			}
		}else{
			scores.push_back(line[idx] - '0');
		}
	}
	int sum = 0;
	for(int score : scores){
		sum += score;
	}
	double avg = sum / (double)scores.size();
	cout << fixed << setprecision(2) << round(avg * 100) / 100;
	return 0;
}
