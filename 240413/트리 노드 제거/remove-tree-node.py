N = int(input())
parents = list(map(int, input().split()))
target = int(input())

root = -1
ans = 0
tree = [[] for _ in range(N)]
deleted = [False for _ in range(N)]

for i in range(N):
    node, par = i, parents[i]

    if par == -1:
        root = node
        continue

    tree[par].append(node)


def dfs(node):
    global ans

    if deleted[node]:
        return
    
    isLeaf = True

    for next in tree[node]:
        if deleted[next]:
            continue
        dfs(next)

        isLeaf = False
    
    if isLeaf:
        ans += 1

deleted[target] = True

dfs(root)

print(ans)