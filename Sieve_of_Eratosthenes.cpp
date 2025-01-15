// Function to generate primes using Sieve of Eratosthenes
// This code genates a vector with all primes in range [1,MAXN]
// Adjust MAXN as per the constraints

const int MAXN = 1000000;
vector<int> primes;

void generate_primes() {
    vector<bool> is_prime(MAXN + 1, true);
    is_prime[0] = is_prime[1] = false;
    
    for (int i = 2; i * i <= MAXN; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAXN; j += i) {
                is_prime[j] = false;
            }
        }
    }
    
    for (int i = 2; i <= MAXN; i++) {
        if (is_prime[i]) primes.push_back(i);
    }
}