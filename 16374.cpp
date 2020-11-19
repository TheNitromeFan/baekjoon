#include <cstdio>
#include <utility>
#include <algorithm>

using namespace std;

int gcd(int a, int b){
	if(b == 0){
		return a;
	}else{
		return gcd(b, a % b);
	}
}

bool valid_labeling(vector<int> &label, pair<int, int> edge[10], int n){
	for(int i = 0; i < n - 1; ++i){
		if(gcd(label[edge[i].first - 1], label[edge[i].second - 1]) > 1){
			return false;
		}
	}
	return true;
}

int main(){
	FILE *fp1 = fopen("data-2.in", "r");
	FILE *fp2 = fopen("16374.txt", "w");
	int t;
	fscanf(fp1, "%d", &t);
	for(int a0 = 0; a0 < t; ++a0){
		printf("%d\n", a0);
		int n;
		fscanf(fp1, "%d", &n);
		pair<int, int> edge[10];
		for(int i = 0; i < n - 1; ++i){
			fscanf(fp1, "%d %d", &edge[i].first, &edge[i].second);
		}
		vector<int> label(n);
		for(int i = 0; i < n; ++i){
			label[i] = i + 1;
		}
		do{
			if(valid_labeling(label, edge, n)){
				for(int i = 0; i < n; ++i){
					fprintf(fp2, "%d ", label[i]);
				}
				fprintf(fp2, "\n");
				break;
			}
		}while(next_permutation(label.begin(), label.end()));
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}
