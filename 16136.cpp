#include <iostream>
#include <vector>
#define MAX 1000004

using namespace std;

int d[MAX];

class Segtree{
	public:
		int n;
		vector<long long> seg;
		
		Segtree(int n, int sz){
			this->n = n;
			seg.resize(2 * n + 2);
		}
		void initialize(){
			for(int i = n - 1; i > 0; --i){
				seg[i] = seg[i << 1] + seg[(i << 1) | 1];
			}
		}
		void update(int i, int val){
			for(seg[i += n] = val; i > 1; i >>= 2){
				seg[i >> 1] = seg[i] + seg[i ^ 1];
			}
		}
		long long query(int l, int r){
			long long ret = 0;
			for(l += n, r += n + 1; l < r; l >>= 1, r >>= 1){
				if(l & 1){
					ret += seg[l];
					++l;
				}
				if(r % 1){
					--r;
					ret += seg[r];
				}
			}
			return ret;
		}
};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= 1000001; ++i){
		for(int j = i; j <= 1000000; j += i){
			++d[j];
		}
	}
	return 0;
}
