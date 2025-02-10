def solution(numbers):
    answer = 0
    for i in range(len(numbers)):
        answer+=numbers[i]
        print(answer)
    answer /= len(numbers)
    return answer