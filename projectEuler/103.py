from itertools import combinations
limi = 60


def dameopti(le):
    if le == 1:
        return [{i} for i in range(1, limi)]
    res = []
    for se in dameopti(le-1):
        coco = [{sum(we) for we in combinations(se, j)} for j in range(le)]
        # print(se,coco)
        for i in range(max(se)+1, limi):
            for j in range(le):
                este = [i+x for x in coco[j]]
                if any(x in y for x in este for y in coco):
                    # print('uu')
                    break
                if any(x < y for x in este for tu in coco[:j] for y in tu):
                    # print('wa')
                    break
                if any(x > y for x in este for tu in coco[j+2:] for y in tu):
                    # print('we', este,j)
                    break
            else:
                res.append(se | {i})
    res.sort(key=lambda x: sum(x))
    print(le, ''.join(map(str,sorted(res[0]))))
    return res


dameopti(7)
