#include <iostream>
#include <cmath>
#include <conio.h>
#define ll long long

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

bool is_prime(ll p){
	if(p <= 1 )
		return false;
	
	for(int i=0; i <50; i++){
		ll n = rand()%(p-1) + 1;
		
		if(modular_exponentiation(n, p-1, p) != 1)
			return false;
	}
	return true;	
}

int main()
{
	cout << "Enter any number  ";
	ll p;
	cin >> p;
	
	if(is_prime(p))
		cout << p << " is a prime number.";
	else
		cout << p << " is not a prime number.";
	
//	getch();
	
	return 0;
}
