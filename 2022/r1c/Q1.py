
import string

def solve(case):
    n = int(input())
    ss = input().split(' ')
    l = []
    sames = {};
    for c in string.ascii_uppercase:
        sames[c] = 0
    for s in ss:
        if s == '':
            continue
        same = True
        for j in range(len(s)):
            if s[j] != s[0]:
                same = False
                break
        if same:
            sames[s[0]] += len(s)
        else:
            l.append(s)
    
    m = len(l);

    start = {}
    end = {}
    for i in range(m):
        s = l[i][0]
        e = l[i][-1]
        if s in start:
            print("Case #" + str(case) + ": IMPOSSIBLE")
            return
        if e in end:
            print("Case #" + str(case) + ": IMPOSSIBLE")
            return
        start[s] = l[i]
        end[e] = l[i]


    vis = set()
    res = ""
    cur = ''
    for i in range(m):
        if cur not in start:
            valid = False
            for i in range(m):
                if l[i] not in vis:
                    if l[i][0] not in end:
                        cur = l[i][0]
                        valid = True
                        res += cur * sames[cur]
                        sames[cur] = 0
                        break
            if not valid:
                print("Case #" + str(case) + ": IMPOSSIBLE")
                return

        res += start[cur]
        vis.add(start[cur])
        cur = res[-1]
        res += cur * sames[cur]
        sames[cur] = 0

    for c in string.ascii_uppercase:
        if sames[c] > 0:
            res += c * sames[c]
            sames[c] = 0
    
    seen = set()
    for i in range(len(res)):
        if i > 0 and res[i] == res[i - 1]:
            continue
        if res[i] in seen:
            print("Case #" + str(case) + ": IMPOSSIBLE")
            print(res[i])
            print(i)
            return
        seen.add(res[i])

    print("Case #" + str(case) + ": " + res)

    

t = int(input())
for i in range(t):
    solve(i + 1)