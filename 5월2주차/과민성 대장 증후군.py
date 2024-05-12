N,M = map(int,input())
sum=0
cnt=0
stress_li = list(map(int,input()))

for stress in stress_li:
    sum = max(0,sum+stress)
    if sum>= M:
        cnt+=1
        
print(cnt)