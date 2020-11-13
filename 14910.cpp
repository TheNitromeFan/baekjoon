#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector<int> a;
	int x;
	while(scanf("%d", &x) == 1){
		a.push_back(x);
	}
	if(prev_permutation(a.begin(), a.end())){
		printf("Bad");
	}else{
		printf("Good");
	}
	return 0;
}
