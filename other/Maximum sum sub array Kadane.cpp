#include <iostream>
#define endl "\n"
#define ll long long

using namespace std;

inline int max(int x, int y){
	if(x < y)
		return y;
	return x;
}

int max_sum_subarray(int arr[], int n){
	int ans = 0, sum = 0;
	for(int i=0; i<n; i++){
		if(sum + arr[i] > 0)
			sum += arr[i];
		else
			sum = 0;
		ans = max(ans, sum);
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	
	int arr[] = {4, 8, -6, 9, -1};
	
	cout << max_sum_subarray(arr, 5) << endl;
	
	
	return 0;
}
