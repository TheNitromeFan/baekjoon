def stack_length(plates):
    answer = 10
    for i in range(1, len(plates)):
        if plates[i] is plates[i-1]:
            answer += 5
        else:
            answer += 10
    return answer


print(stack_length(input()))
