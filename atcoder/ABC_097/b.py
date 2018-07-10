x = int (input());

max = 0;

for i in range(x):
    for j in range(x):
        num = i**j;
        if num > max and x >= num:
            max = num

print(max)
