N,K = map(int,input().split())
li = []
for i in range(N) :
    li.append(int(input()))

li.reverse()
cnt=0
for i in li:
    while K >= i:
        cnt+=1
        K-=i
        
print(cnt)