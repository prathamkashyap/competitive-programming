import sys

def main():
    data = sys.stdin.buffer.read().split()
    idx = 0
    t = int(data[idx]); idx += 1
    out = []
    for _ in range(t):
        n = int(data[idx]); idx += 1
        f = [int(x) for x in data[idx:idx+n]]
        idx += n
        
        a = [0] * (n + 1)  # 1-indexed a[1..n]
        
        # a_j for j=2..n-1 : a[j] = (f(j+1) - 2f(j) + f(j-1)) / 2
        for j in range(2, n):
            a[j] = (f[j] - 2*f[j-1] + f[j-2]) // 2
        
        sum1 = 0  # sum a_i*(i-1) for i=2..n-1
        sum2 = 0  # sum a_i*(n-i) for i=2..n-1
        for i in range(2, n):
            sum1 += a[i] * (i - 1)
            sum2 += a[i] * (n - i)
        
        a[n] = (f[0] - sum1) // (n - 1)
        a[1] = (f[n-1] - sum2) // (n - 1)
        
        out.append(' '.join(map(str, a[1:n+1])))
    
    sys.stdout.write('\n'.join(out) + '\n')

main()