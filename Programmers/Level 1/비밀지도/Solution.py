def solution(n, arr1, arr2):
    answer = decode_map(to_binary(n, arr1), to_binary(n, arr2))
    return answer

def to_binary(n, arr):
    result = []
    for a in arr:
        b = bin(a)[2:]
        if len(b) < n:
            result.append("0"*(n-len(b)) + b)
        else:
            result.append(b)
    return result

def decode_map(arr1, arr2):
    map = []
    for i in range(len(arr1)):
        row = ""
        for j in range(len(arr1)):
            if arr1[i][j] == '1' or arr2[i][j] == '1':
                row += "#"
            else:
                row += " "
        map.append(row)
    return map