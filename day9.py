def main():
    f = open("./day9.txt", "r")
    lines = f.readlines()
    lines = [row.rstrip() for row in lines]

    tails = [[0, 0] for x in range(10)]
    # print(len(tails))
    visited = [str([0, 0])]

    for x in lines:
        row = x.split(" ")
        move = int(row[1])

        while move > 0:
            for i in range(len(tails)):
                if i == 0:
                    if row[0] == "R":
                        tails[i][0] += 1
                    elif row[0] == "L":
                        tails[i][0] -= 1
                    elif row[0] == "U":
                        tails[i][1] += 1
                    elif row[0] == "D":
                        tails[i][1] -= 1
                    move -= 1
                else:
                    if tails[i][0] == tails[i - 1][0] or tails[i][1] == tails[i - 1][1]:
                        if tails[i][0] == tails[i - 1][0]:
                            if tails[i][1] < tails[i - 1][1] - 1:
                                tails[i][1] = tails[i - 1][1] - 1
                            elif tails[i][1] > tails[i - 1][1] + 1:
                                tails[i][1] = tails[i - 1][1] + 1
                        elif tails[i][1] == tails[i - 1][1]:
                            if tails[i][0] < tails[i - 1][0] - 1:
                                tails[i][0] = tails[i - 1][0] - 1
                            elif tails[i][0] > tails[i - 1][0] + 1:
                                tails[i][0] = tails[i - 1][0] + 1
                    elif tails[i][0] < tails[i - 1][0] - 1 and tails[i][1] < tails[i - 1][1] - 1:
                        tails[i][0] = tails[i - 1][0] - 1
                        tails[i][1] = tails[i - 1][1] - 1
                    elif tails[i][0] < tails[i - 1][0] - 1 and tails[i][1] > tails[i - 1][1] + 1:
                        tails[i][0] = tails[i - 1][0] - 1
                        tails[i][1] = tails[i - 1][1] + 1
                    elif tails[i][0] > tails[i - 1][0] + 1 and tails[i][1] > tails[i - 1][1] + 1:
                        tails[i][0] = tails[i - 1][0] + 1
                        tails[i][1] = tails[i - 1][1] + 1
                    elif tails[i][0] > tails[i - 1][0] + 1 and tails[i][1] < tails[i - 1][1] - 1:
                        tails[i][0] = tails[i - 1][0] + 1
                        tails[i][1] = tails[i - 1][1] - 1
                    elif tails[i][0] < tails[i - 1][0] - 1:
                        tails[i][0] = tails[i - 1][0] - 1
                        tails[i][1] = tails[i - 1][1]
                        # if tails[i][1] < tails[i - 1][1]:
                        #     tails[i][0] = tails[i - 1][0] - 1
                        #     tails[i][1] = tails[i - 1][1]
                        # elif tails[i][1] > tails[i - 1][1]:
                        #     tails[i][0] = tails[i - 1][0] - 1
                        #     tails[i][1] = tails[i - 1][1]
                    elif tails[i][0] > tails[i - 1][0] + 1:
                        tails[i][0] = tails[i - 1][0] + 1
                        tails[i][1] = tails[i - 1][1]
                    elif tails[i][1] > tails[i - 1][1] + 1:
                        tails[i][0] = tails[i - 1][0]
                        tails[i][1] = tails[i - 1][1] + 1
                    elif tails[i][1] < tails[i - 1][1] - 1:
                        tails[i][0] = tails[i - 1][0]
                        tails[i][1] = tails[i - 1][1] - 1
                    # elif tails[i][0] > tails[i - 1][0]:
                    #     if tails[i][1] < tails[i - 1][1] - 1:
                    #         tails[i][0] = tails[i - 1][0] - 1
                    #         tails[i][1] = tails[i - 1][1] + 1
                    #     elif tails[i][1] > tails[i - 1][1] + 1:
                    #         tails[i][0] = tails[i - 1][0] - 1
                    #         tails[i][1] = tails[i - 1][1] - 1
                    #     else:
                    #         tails[i][0] = tails[i - 1][0] - 1
                    #         tails[i][1] = tails[i - 1][1] - 1


                if i == 9:
                    print(tails)
                    visited.append(str(tails[i]))

    print(set(visited))
    print(len(set(visited)))


if __name__ == '__main__':
    main()
