#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	vector<int> scores(n);
	for(int i = 0; i < n; ++i){
		double score;
		scanf("%lf", &score);
		scores[i] = 10 * score;
	}
	sort(scores.begin(), scores.end());
	int sum = 0;
	for(int i = k; i < n - k; ++i){
		sum += scores[i];
	}
	int judges = n - 2 * k;
	int avg = 10 * sum / judges;
	if((10 * sum % judges) * 2 >= judges){
		++avg;
	}
	printf("%d.%02d\n", avg / 100, avg % 100);
	for(int i = 0; i < k; ++i){
		sum += scores[k] + scores[n - 1 - k];
	}
	avg = 10 * sum / n;
	if((10 * sum % n) * 2 >= n){
		++avg;
	}
	printf("%d.%02d\n", avg / 100, avg % 100);
	return 0;
}
