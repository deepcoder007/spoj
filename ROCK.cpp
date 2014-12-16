
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <utility>
using namespace std;

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }



int main() {
	int t, n, i, j, add, cnt;
	int memo[256];
	char rock[256];
	scanf("%d", &t);
	while(t--) {
		scanf("%d%s", &n, rock);
		memo[0] = rock[0]-'0';
		for(i = 1; i < n; i++) {
			memo[i] = memo[i-1];
			cnt = 0;
			for(j = i; j >= 0; j--) {
				cnt += ((rock[j]=='1')? 1 : -1);
				if(cnt > 0) {
					add = i - j + 1;
					if(j > 0) add += memo[j-1];
					setmax(memo[i], add);
				}
			}
		}
		printf("%d\n", memo[n-1]);
	}
	return 0;
}
