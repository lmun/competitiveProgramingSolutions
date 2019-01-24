while True:
    try:
        line = input().strip()
        pre = []
        suc = []
        for c in line:
            if c == '[':
                pre.extend(suc)
                suc = pre
                pre = []
            elif c == ']':
                pre.extend(suc)
                suc = []
            else:
                pre.append(c)
        pre.extend(suc)
        print(''.join(pre))
    except Exception as e:
        break