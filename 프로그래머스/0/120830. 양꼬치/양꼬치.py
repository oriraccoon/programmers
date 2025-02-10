def solution(n, k):
    answer = 0
    if n >= 10:
        services = n // 10
        return n*12000 + (k-services)*2000
    else:
        return n*12000+k*2000
    return answer