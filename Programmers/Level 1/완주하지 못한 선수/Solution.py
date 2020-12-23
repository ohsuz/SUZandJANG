def solution(participant, completion):
  part = {}
  for p in participant:
      part[p] = part.get(p, 0) + 1

  for c in completion:
      part[c] = part.get(c) - 1
      if part[c] == 0: del part[c]

  return list(part.keys())[0]