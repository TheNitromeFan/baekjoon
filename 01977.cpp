#include <iostream>
#include <cmath>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

static vector<int> squares(double m, double n){
	int start = static_cast<int>(ceil(sqrt(m)));
	int end = static_cast<int>(floor(sqrt(n)));
	vector<int> result = {0, -1};
	for(int i = start; i <= end; ++i){
		result[0] += i*i;
		if(result[1] == -1)
			result[1] = i*i;
	}
	return result;
}

int main(){
	double m = 0.0, n = 0.0;
	cin >> m >> n;
	vector<int> v = squares(m, n);
	if(v[0] > 0)
		cout << v[0] << endl;
	cout << v[1] << endl;
	return 0;
}
