#include <cstdio>
#define ll long long
using namespace std;

inline void fastRead(ll *a)
{
	register char c=0;
	while (c<33)
		c=getchar_unlocked();
	*a=0;
	while (c>33)
	{
		*a=*a*10+c-'0';
		c=getchar_unlocked();
	}
}

int main()
{
	ll n, k;
	fastRead(&n);
	fastRead(&k);
	ll count = 0;
	while(n--){
		ll a;
		fastRead(&a);
		if(a%k == 0)
			count++;
	}
	printf("%lld", count);
	return 0;
}
