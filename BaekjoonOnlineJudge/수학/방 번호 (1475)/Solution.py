'''
딴건 몰라도 코드가 더럽단건 알겠다
하지만 졸리니까 내일,, 다시 봐야지,,,
'''
N = input()
sets = ['0123456789' for _ in range(len(N))]
index, cnt = [0 for _ in range(10)], [0 for _ in range(10)]

for num in N:
  i = index[int(num)]
  if num in sets[i]:
    sets[i] = sets[i].replace(num, '')
    cnt[int(num)] += 1
    if num not in '69':
      index[int(num)] += 1
  else:
    if num == '6' and '9' in sets[i]:
      sets[i] = sets[i].replace('9', '')
      cnt[9] += 1
      index[6] += 1
      index[9] += 1
    elif num == '9' and '6' in sets[i]:
      sets[i] = sets[i].replace('6', '')
      cnt[6] += 1
      index[6] += 1
      index[9] += 1
    else:
      sets[i+1] = sets[i+1].replace(num, '')
      cnt[int(num)] += 1
      index[int(num)] += 1

print(max(cnt))