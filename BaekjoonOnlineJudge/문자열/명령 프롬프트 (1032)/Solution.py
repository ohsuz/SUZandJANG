answer = ''
N = int(input())
files = sorted([input() for _ in range(N)], key=len, reverse=True)

for i in range(len(files[0])):
  temp = []
  for file in files:
    if len(file) > i:
      temp.append(file[i])
    else:
      answer += '?'
      break
  else:
    if len(set(temp)) == 1:
      answer += temp[0]
    else:
      answer += '?'

print(answer)
