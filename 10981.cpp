#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
#include <set>

using namespace std;

class Cmp{
	public:
		bool operator()(tuple<string, string, int, int> a, tuple<string, string, int, int> b){
			return get<2>(a) > get<2>(b) || (get<2>(a) == get<2>(b) && get<3>(a) < get<3>(b));
		}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	unsigned n, k;
	cin >> n >> k;
	vector<tuple<string, string, int, int>> scores(n);
	for(unsigned i = 0; i < n; ++i){
		cin >> get<0>(scores[i]) >> get<1>(scores[i]) >> get<2>(scores[i]) >> get<3>(scores[i]);
	}
	sort(scores.begin(), scores.end(), Cmp());
	set<string> colleges;
	unsigned idx = 0;
	while(colleges.size() < k){
		string college = get<0>(scores[idx]), team = get<1>(scores[idx]);
		if(colleges.find(college) == colleges.end()){
			colleges.insert(college);
			cout << team << "\n";
		}
		++idx;
	}
	return 0;
}
