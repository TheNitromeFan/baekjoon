#include <iostream>
#include <cstdlib>

using namespace std;

long min(long a, long b){
	
	if(a < b) return a;
	else return b;
}

long operations(long number){
	
	long *counts = (long *)malloc((number+1) * sizeof(long));
	counts[0] = 0;
	counts[1] = 0;
	for(long i = 2; i <= number; i++){
		counts[i] = counts[i-1] + 1;
		if(i % 2 == 0) counts[i] = min(counts[i], counts[i/2] + 1);
		if(i % 3 == 0) counts[i] = min(counts[i], counts[i/3] + 1);
	}
	long answer = counts[number];
	free(counts);
	return answer;
}

int main(void){
	
	long n;
	cin >> n;
	cout << operations(n);
	return 0;
}
