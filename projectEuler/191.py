ul = [
    1,  # sin a sin l - 0
    1,  # con a sin l - 1
    0,  # con aa sin l - 2
    1,  # sin aa con l - 3
    0,  # con a con l - 4
    0,  # con aa con l - 5
]
for i in range(2,35):
    ul = [
        ul[0]+ul[1]+ul[2],  # sin a sin l
        ul[0],
        ul[1],
        ul[0]+ul[1]+ul[2]+ul[3]+ul[4]+ul[5],
        ul[3],
        ul[4],
    ]
    print(i,sum(ul))
