// This Code Calculates pow(a,b)
// Time Complexity log(b) 
int binary_exp(ll a, ll b)
{
	int ans = 1;
	while(b){
		if(b & 1) ans = (ans * 1LL * a) % MOD;
		a = (a * 1LL * a) % MOD;
		b >>= 1;
	}
	return ans;
}