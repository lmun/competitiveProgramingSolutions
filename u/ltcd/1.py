def robotSim(commands, obstacles):
    dirs = [(1,0),(0,-1),(-1,0),(0,1)]
    """
    :type commands: List[int]
    :type obstacles: List[List[int]]
    :rtype: int
    """
    mdi = 0
    dir = 3
    obs = set()
    px, py = 0, 0
    for ob in obstacles:
        obs.add((ob[0], ob[1]))
    for c in commands:
        if c == -1:
            dir += 1
            dir %= 4
        elif c == -2:
            dir += 3
            dir %= 4
        else:
            for _ in range(c):
                if (px+dirs[dir][0], py+dirs[dir][1]) not in obs:
                    px, py = px+dirs[dir][0], py+dirs[dir][1]
                    print(px, py)
                    mdi = max(mdi, px*px+py*py)
    return mdi

robotSim([4,-1,4,-2,4], [[2,4]])
