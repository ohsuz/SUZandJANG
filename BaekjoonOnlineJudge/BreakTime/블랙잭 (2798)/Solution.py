from itertools import combinations

n, m = map(int, input().split())
cards = map(int, input().split())
answer = 0

for card in combinations(cards, 3):
    if answer < sum(card) <= m:
        answer = sum(card)
        if sum(card) == m:
            break

print(answer)
