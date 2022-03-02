# 2303 숫자 게임
# https://www.acmicpc.net/problem/2303
N = int(input())
card = []
answer_idx = 0
maxnum = -1
for x in range(N):
    card.append(list(map(int, input().split())))

for i in range(1, N + 1):
    for j in range(125):
        a = j % 5
        b = (j // 5) % 5
        c = j // 25
        if a == b or b == c or c == a:
            continue
        num = (card[i - 1][a] + card[i - 1][b] + card[i - 1][c]) % 10
        if maxnum <= num:
            maxnum = num
            answer_idx = i
print(answer_idx)
        