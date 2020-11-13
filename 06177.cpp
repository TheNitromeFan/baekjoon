#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<int> x(n, 0);
	int sum = 0;
	for(int i = 0; i < n; ++i){
		scanf("%d", &x[i]);
		sum += x[i];
	}
	double mean = sum / (double)n;
	sort(x.begin(), x.end());
	double median;
	if(n % 2){
		median = x[n / 2];
	}else{
		median = (x[n / 2 - 1] + x[n / 2]) / 2.0;
	}
	printf("%f\n%f", mean, median);
	return 0;
}
