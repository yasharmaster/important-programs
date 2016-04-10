#include <iostream>
#include <cmath>
#include <conio.h>

#define ll long long

/*
https://www.khanacademy.org/computing/computer-science/cryptography/modarithmetic/a/fast-modular-exponentiation
Khan Academy modular exponentiation (fast)

*/



using namespace std; 	

ll modular_exponentiation(ll base, ll exponent, ll mod){ 	//
	ll result = 1;
	
	while(exponent > 0){
		if(exponent & 1)
			result = (result*base)%mod;
				
		exponent = exponent >> 1;
		base = (base*base)%mod;
	}
	
	return result;
}

int main()
{
	ll base, exp, mod;
	cin >> base >> exp >> mod;
	cout << "\n" << modular_exponentiation(base, exp, mod) << endl;

	return 0;
}
