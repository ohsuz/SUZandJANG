num = int(input())
length = len(str(num))

for i in range(num//2, num):
  if i + sum(map(int, list(str(i)))) == num:
    print(i)
    break

else:
  print(0)
