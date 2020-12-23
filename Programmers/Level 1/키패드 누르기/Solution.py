def solution(numbers, hand):
    answer = ''    
    left = '*'
    right = '#'
    
    for n in numbers:
        if n in [1, 4, 7]:
            answer += 'L'
            left = n
        elif n in [3, 6, 9]:
            answer += 'R'
            right = n
        else:
            d_left = get_distance(left, n)
            d_right = get_distance(right, n)

            if d_left == d_right:
                if hand == "right":
                    answer += 'R'
                    right = n
                else:
                    answer += 'L'
                    left = n
            if d_left > d_right:
                answer += 'R'
                right = n
            if d_left < d_right:
                answer += 'L'
                left = n
    
    return answer

def get_distance(cur, target):
    keypads = {1: [0, 0], 2: [0, 1], 3: [0, 2],
              4: [1, 0], 5: [1, 1], 6: [1, 2],
              7: [2, 0], 8: [2, 1], 9: [2, 2],
              '*': [3, 0], 0: [3, 1], '#': [3, 2]}
    
    cur_pos = keypads[cur]
    target_pos = keypads[target]
    
    return abs(cur_pos[0]-target_pos[0]) + abs(cur_pos[1]-target_pos[1])