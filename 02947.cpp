#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool ordered(vector<int> v){
	return !prev_permutation(v.begin(), v.end());
}

void output(vector<int> &v, int x, int y){
	swap(v[x], v[y]);
	for(int i = 0; i < 5; ++i){
		printf("%d ", v[i]);
	}
	printf("\n");
}

int main(){
	vector<int> v(5, 0);
	for(int i = 0; i < 5; ++i){
		scanf("%d", &v[i]);
	}
	do{
		for(int j = 0; j < 4; ++j){
			if(v[j] > v[j + 1]){
				output(v, j, j + 1);
			}
		}
	}while(!ordered(v));
	return 0;
}
