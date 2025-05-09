// binary multiplication code
int binary_mult(ll a, ll b)
{
	int ans = 1;
	while(b > 0){
		if(b & 1){
			ans = (ans + a) % MOD;
		}
		a = (a + a) % MOD;
		b >>= 1;
	}
	return ans;
}