MOD = 10**9 + 7

def weighted_sum(n, k):
    a = (n // k + 1) % MOD
    b = (n // (k - 1)) % MOD
    n_terms = (b - a + 1 + MOD) % MOD
    sum_ = (n_terms * (a + b) % MOD) * 500000004 % MOD
    to_add = (sum_ * ((k - 1) % MOD)) % MOD
    return to_add

def main():
    n = int(input())
    n %= MOD
    if n == 1:
        print(1)
        return
    ans = n
    i = 2
    s = []
    while i*i <= n:
        s.append(n//i)
        ans = (ans + weighted_sum(n, i)) % MOD
        i += 1
    if s[-1] + 1 != i and (n//i != n//(i-1)):
        ans = (ans + weighted_sum(n, i)) % MOD
    for i in range(len(s)-1, -1, -1):
        ans = (ans + weighted_sum(n, s[i]+1)) % MOD
    print(ans)

if __name__ == "__main__":
    main()