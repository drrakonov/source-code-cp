// To Calculate phi(n) in euler totient function
// To further Calculate the value of pow(x,y) % MOD  use binary exponentiation

int gcd(ll a, ll b)
{
    if (a == 0){
        return b;
    }
    return gcd(b % a, a);
}

int phi(ll n)
{
    int ans = 1;
    for (ll i = 2; i < n; i++){
        if (gcd(i, n) == 1){
            ans++;
        }
    }
    return ans;
}