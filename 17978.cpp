#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Point{
	int x;
	int y;
	int z;
};

double c(vector<Point> &v){
	if(v.empty()){
		return 0;
	}
	long long sr = 0, sg = 0, sb = 0, sqr = 0, sqg = 0, sqb = 0;
	int cnt = 0;
	for(Point p : v){
		sr += p.x;
		sg += p.y;
		sb += p.z;
		sqr += p.x * p.x;
		sqg += p.y * p.y;
		sqb += p.z * p.z;
		++cnt;
	}
	return sqr + sqg + sqb - (sr * sr + sg * sg + sb * sb) / (double)cnt;
}

int dot_product(Point p1, Point p2){
	return p1.x * p2.x + p1.y * p2.y + p1.z * p2.z;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	if(n <= k){
		cout << fixed << setprecision(6) << 0.0 << '\n';
		return 0;
	}
	vector<Point> v(n);
	for(int i = 0; i < n; ++i){
		int x, y, z;
		cin >> x >> y >> z;
		v[i].x = x;
		v[i].y = y;
		v[i].z = z;
	}
	if(k == 1){
		cout << fixed << setprecision(6) << c(v) << '\n';
		return 0;
	}
	double ans = 1e9;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < i; ++j){
			for(int k = 0; k < j; ++k){
				Point p = v[i], q = v[j], r = v[k];
				Point norm;
				norm.x = (q.y - p.y) * (r.z - p.z) - (q.z - p.z) * (r.y - p.y);
				norm.y = (q.z - p.z) * (r.x - p.x) - (q.x - p.x) * (r.z - p.z);
				norm.z = (q.x - p.x) * (r.y - p.y) - (q.y - p.y) * (r.x - p.x);
				vector<Point> a, b;
				for(int m = 0; m < n; ++m){
					if(m == i || m == j || m == k){
						continue;
					}
					Point tmp;
					tmp.x = v[m].x - p.x;
					tmp.y = v[m].y - p.y;
					tmp.z = v[m].z - p.z;
					if(dot_product(tmp, norm) > 0){
						a.push_back(v[m]);
					}else{
						b.push_back(v[m]);
					}
				}
				a.push_back(v[i]);
				a.push_back(v[j]);
				a.push_back(v[k]);
				ans = min(ans, c(a) + c(b));
				a.pop_back();
				a.pop_back();
				a.pop_back();
				a.push_back(v[i]);
				a.push_back(v[j]);
				b.push_back(v[k]);
				ans = min(ans, c(a) + c(b));
				a.pop_back();
				a.pop_back();
				b.pop_back();
				a.push_back(v[i]);
				b.push_back(v[j]);
				a.push_back(v[k]);
				ans = min(ans, c(a) + c(b));
				a.pop_back();
				b.pop_back();
				a.pop_back();
				a.push_back(v[i]);
				b.push_back(v[j]);
				b.push_back(v[k]);
				ans = min(ans, c(a) + c(b));
				a.pop_back();
				b.pop_back();
				b.pop_back();
				b.push_back(v[i]);
				a.push_back(v[j]);
				a.push_back(v[k]);
				ans = min(ans, c(a) + c(b));
				b.pop_back();
				a.pop_back();
				a.pop_back();
				b.push_back(v[i]);
				a.push_back(v[j]);
				b.push_back(v[k]);
				ans = min(ans, c(a) + c(b));
				b.pop_back();
				a.pop_back();
				b.pop_back();
				b.push_back(v[i]);
				b.push_back(v[j]);
				a.push_back(v[k]);
				ans = min(ans, c(a) + c(b));
				b.pop_back();
				b.pop_back();
				a.pop_back();
				b.push_back(v[i]);
				b.push_back(v[j]);
				b.push_back(v[k]);
				ans = min(ans, c(a) + c(b));
				b.pop_back();
				b.pop_back();
				b.pop_back();
			}
		}
	}
	cout << fixed << setprecision(6) << ans << '\n';
	return 0;
}
