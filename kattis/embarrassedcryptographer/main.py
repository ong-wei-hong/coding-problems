primes = []

def solve(K, L):
    for i in primes:
        if L <= i:
            break
        if K % i == 0:
            print('BAD {}'.format(i))
            return

    print('GOOD')

def generate_primes(limit):
    m = [True for _ in range(limit+1)]
    for i in range(2, limit+1):
        if(m[i]):
            primes.append(i)
            for j in range(i,limit+1,i):
                m[j]=False

if __name__ == "__main__":
    generate_primes(int(10e6))
    while True:
        a,b = tuple(map(int, input().split(' ')))
        if a == 0 and b == 0:
            break
        solve(a,b)

