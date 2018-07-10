N = int(input())
a = [int(i) for i in input().split()]
count = 0

for j in range(0, N):
    sum = 0;
    for i in range(j, N):
        sum += a[i]
        if sum == 0:
            count += 1

print(count)
