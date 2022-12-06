/*A digit string is good if the digits (0-indexed) at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).

For example, "2582" is good because the digits (2 and 8) at even positions are even and the digits (5 and 2) at odd positions are prime. However, "3245" is not good because 3 is at an even index but is not even.
Given an integer n, return the total number of good digit strings of length n. Since the answer may be large, return it modulo 109 + 7.

A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.*/
#define ll long long 
class Solution {
public:
    //TC: O(log n)
    //SC: O(log n)
    //Each even index will contain any of the 5 evens -> 0,2,4,6,8
    //Each odd index will contain any of the 4 primes-> 2,3,5,7
    //if there are n digits, the  ans is 5*4*5*4*......n times
    int p = 1e9+7;
    ll power(ll x, ll n){
        //base case
        if(n == 0)
            return 1;

        ll temp = power(x,n/2) % p;
        if(n&1)          //Power is odd
            return temp * temp * x; 
        else
            return temp * temp;
    }

    int countGoodNumbers(long long n) {
        ll count4 = n/2;
        ll count5 = n-n/2;
        ll ans = ((power(4LL, count4) % p) * (power(5LL, count5) % p))%p;  //( a * b) % c = ( ( a % c ) * ( b % c ) ) % c
        return (int)ans;
    }
};
