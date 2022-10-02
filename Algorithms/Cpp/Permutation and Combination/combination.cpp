#include <bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
typedef long long ll;

ll perumator(ll p, ll n)
{
	ll fac = 1;
	ll c = 1;
	for (ll i = p; i <= n; i++)
	{
		fac = fac * i / c;
		c++;
		if (c > n - p + 1)
			c = 1;
	}
	return fac;
}

ll nCr(ll n, ll r) {
	if (r <= n / 2)
		return perumator(n - r + 1, n);
	else
		return perumator(r + 1, n) ;
}
int main()
{
	ll n, r;
	cin >> n >> r;
	ll combination = nCr(n, r);
	cout << combination;
	return 0;
}