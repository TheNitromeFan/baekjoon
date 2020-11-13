#include <iostream>
#include <vector>

using namespace std;

int count_subseq(vector<int> seq, int s){
	if(seq.size() == 0){
		return s == 0;
	}else{
		int x = seq[seq.size()-1];
		seq.pop_back();
		return count_subseq(seq, s-x) + count_subseq(seq, s);
	}
}

int main(){
	int n, s;
	cin >> n >> s;
	vector<int> a;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		a.push_back(x);
	}
	int cnt = count_subseq(a, s);
	if(s == 0){
		--cnt;
	}
	cout << cnt << endl;
	return 0;
}
