#include <iostream>
#include <cmath>
#include <conio.h>

using namespace std;



int main()
{
	cout << "Enter a number.  ";
	int n;
	cin >> n;	
//	n=100;	
	int is_prime[n+1];
	for(int i=2; i<=n; i++)
		is_prime[i] = 1;
	
	for(int i=4; i<=n; i+=2)		//First cross out all the multiples of 2
		is_prime[i] = 0;
	
	for(int i=3; i <= sqrt(n); i++){		//start with 3 here
		if(is_prime[i] == 1){
			for(int j = i*i; j <= n; j += i*2){		//start cossing out from i*i and only cross out every other multiple of i thats why 2*i not just i
				is_prime[j] = 0;	
			}
		}
	}
	int count = 0;
	for(int i=2; i <=n; i++){
		if(is_prime[i] == 1){
			cout << i << endl;
			count++;
		}
	}
	cout << "There are a total of " << count << " prime numbers upto " << n << ".\n"; 

	return 0;
}
