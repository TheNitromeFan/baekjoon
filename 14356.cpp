#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<string>
#include<stack>
#include<set>
#include<map>
#include<cstring>
#include<complex>
#include<cmath>
#include<iomanip>
#include<numeric>
#include<algorithm>
#include<list>
#include<functional>
#include<cassert>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define INF 987654321987654321
#define PI 3.14159265358979323846264
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset(a,0,sizeof(a));
#define MEM_1(a) memset(a,-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<double, double> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<double> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
ll MOD = 1000000007;
ll POW(ll a, ll b, ll MMM = MOD) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,-1,1,0 }, dy[] = { 1,0,0,-1 };
int ddx[] = { 0,0,1,1,1,-1,-1,-1 }, ddy[] = { 1,-1,1,0,-1,1,0,-1 };

string fin(string c, int n)
{
	if (n == 0)return c;
	if (c == "P")return fin("P", n - 1) + fin("R", n - 1);
	if (c == "R")return fin("R", n - 1) + fin("S", n - 1);
	if (c == "S")return fin("S", n - 1) + fin("P", n - 1);
}
string ms(string s)
{
	if (s.length() == 1)return s;
	int n = s.length();
	string s1 = ms(string(s.begin(), s.begin() + n / 2));
	string s2 = ms(string(s.begin() + n / 2, s.end()));
	if (s1 > s2)swap(s1, s2);
	return s1 + s2;
}
void solve()
{
	int n, R, P, S;
	scanf("%d%d%d%d", &n, &R, &P, &S);
	string str = fin("P", n);
	int r = 0, p = 0, s = 0;
	for (char c : str)
	{
		if (c == 'R')r++;
		else if (c == 'P')p++;
		else s++;
	}
	if (R == r && P == p && S == s)
	{
		cout << ms(str) << '\n';
		return;
	}
	str = fin("R", n);
	r = 0, p = 0, s = 0;
	for (char c : str)
	{
		if (c == 'R')r++;
		else if (c == 'P')p++;
		else s++;
	}
	if (R == r && P == p && S == s)
	{
		cout << ms(str) << '\n';
		return;
	}
	str = fin("S", n);
	r = 0, p = 0, s = 0;
	for (char c : str)
	{
		if (c == 'R')r++;
		else if (c == 'P')p++;
		else s++;
	}
	if (R == r && P == p && S == s)
	{
		cout << ms(str) << '\n';
		return;
	}
	puts("IMPOSSIBLE");
}
int main() {
	int tc;
	scanf("%d", &tc);
	fup(TC, 1, tc, 1)
	{
		printf("Case #%d: ", TC);
		solve();
	}
}
