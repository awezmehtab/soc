n = int(input())

for i in range(2,n+1):
    if n//i != n//(i-1):
        print(f'{i} : {n//i}')