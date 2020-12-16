#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool valid(double x, int n){
	double sum = round(x * n);
	double difference = sum / n;
	return difference - x >= -0.00000001 && difference - x <= 0.000999999999;
}

bool all_valid(vector<double> &scores, int k){
	for(double score : scores){
		if(!valid(score, k)){
			return false;
		}
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<double> scores(n);
	for(int i = 0; i < n; ++i){
		cin >> scores[i];
	}
	for(int k = 1; ; ++k){
		if(all_valid(scores, k)){
			cout << k;
			break;
		}
	}
	return 0;
}
