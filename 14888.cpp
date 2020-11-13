#include <cstdio>
#include <vector>
#include <climits>
#include <utility>

using std::vector;
using std::pair;

int n;
int a[11];

pair<int, int> max_value(vector<char> ops, int adds, int subs, int mults, int divs){
	if(ops.size() == n-1){
		int calc = a[0];
		for(int i = 0; i < ops.size(); ++i){
			if(ops[i] == '+'){
				calc += a[i+1];
			}else if(ops[i] == '-'){
				calc -= a[i+1];
			}else if(ops[i] == '*'){
				calc *= a[i+1];
			}else{
				calc /= a[i+1];
			}
		}
		pair<int, int> p(calc, calc);
		return p;
	}
	pair<int, int> minmax(INT_MIN, INT_MAX);
	pair<int, int> tmp;
	if(adds){
		ops.push_back('+');
		tmp = max_value(ops, adds-1, subs, mults, divs);
		if(minmax.first < tmp.first){
			minmax.first = tmp.first;
		}
		if(minmax.second > tmp.second){
			minmax.second = tmp.second;
		}
		ops.pop_back();
	}
	if(subs){
		ops.push_back('-');
		tmp = max_value(ops, adds, subs-1, mults, divs);
		if(minmax.first < tmp.first){
			minmax.first = tmp.first;
		}
		if(minmax.second > tmp.second){
			minmax.second = tmp.second;
		}
		ops.pop_back();
	}
	if(mults){
		ops.push_back('*');
		tmp = max_value(ops, adds, subs, mults-1, divs);
		if(minmax.first < tmp.first){
			minmax.first = tmp.first;
		}
		if(minmax.second > tmp.second){
			minmax.second = tmp.second;
		}
		ops.pop_back();
	}
	if(divs){
		ops.push_back('/');
		tmp = max_value(ops, adds, subs, mults, divs-1);
		if(minmax.first < tmp.first){
			minmax.first = tmp.first;
		}
		if(minmax.second > tmp.second){
			minmax.second = tmp.second;
		}
		ops.pop_back();
	}
	return minmax;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	int op[4];
	for(int j = 0; j < 4; ++j){
		scanf("%d", &op[j]); // +-*/
	}
	vector<char> v;
	pair<int, int> ans = max_value(v, op[0], op[1], op[2], op[3]);
	printf("%d\n%d", ans.first, ans.second);
	return 0;
}
