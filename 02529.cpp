#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool valid(vector<int> &seq, vector<char> &ineq){
	for(unsigned i = 0; i < ineq.size(); ++i){
		if((ineq[i] == '<' && seq[i] > seq[i + 1]) || (ineq[i] == '>' && seq[i] < seq[i + 1])){
			return false;
		}
	}
	return true;
}

int main(){
	int k;
	scanf("%d\n", &k);
	vector<char> ineq;
	ineq.resize(k);
	for(int i = 0; i < k; ++i){
		scanf("%c ", &ineq[i]);
	}
	vector<int> max_seq, min_seq;
	for(int i = 0; i < k + 1; ++i){
		max_seq.push_back(9 - i);
		min_seq.push_back(i);
	}
	do{
		if(valid(max_seq, ineq)){
			break;
		}
	}while(prev_permutation(max_seq.begin(), max_seq.end()));
	do{
		if(valid(min_seq, ineq)){
			break;
		}
	}while(next_permutation(min_seq.begin(), min_seq.end()));
	for(int x : max_seq){
		printf("%d", x);
	}
	printf("\n");
	for(int x : min_seq){
		printf("%d", x);
	}
	return 0;
}
