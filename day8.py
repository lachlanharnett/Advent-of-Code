
def recur(lines, i, j, up, left, down, right, line_len, orig_tree):
    current = lines[i][j]
    results = [False, False, False, False]
    print([i, j, up, left, down, right])
    print("orig: " + orig_tree)
    if up and lines[i - 1][j] < orig_tree: # and lines[i - 1][j] <= current:
        if i - 1 == 0:
            return True
        results[0] = recur(lines, i - 1, j, 1, 0, 0, 0, line_len, orig_tree)
        if results[0]:
            return True
        # current = lines[i + 1][j]
    if left and lines[i][j - 1] < orig_tree: # and lines[i][j - 1] <= current:
        if j - 1 == 0:
            return True
        results[1] = recur(lines, i, j - 1, 0, 1, 0, 0, line_len, orig_tree)
        if results[1]:
            return True
        # current = lines[i][j + 1]
    if down and lines[i + 1][j] < orig_tree: # and lines[i + 1][j] <= current:
        if i + 1 == line_len:
            return True
        results[2] = recur(lines, i + 1, j, 0, 0, 1, 0, line_len, orig_tree)
        if results[2]:
            return True
        # current = lines[i - 1][j]
    if right and lines[i][j + 1] < orig_tree: # and lines[i][j + 1] <= current:
        if j + 1 == line_len:
            return True
        results[3] = recur(lines, i, j + 1, 0, 0, 0, 1, line_len, orig_tree)
        if results[3]:
            return True
        # current = lines[i][j - 1]
    # print("orig_tree")
    # print("Orig_tree: " + orig_tree)
    return False



def main():
    f = open("./day8.txt", "r")
    lines = f.readlines()
    lines = [row.rstrip() for row in lines]

    count = 0
    for i in range(len(lines)):
        if i == 0 or i == (len(lines) - 1):
            count += 99
        else:
            for j in range(len(lines[i])):
                # print(len(lines[0]) - 1)
                if j == 0 or j == (len(lines[i]) - 1):
                    # print(i, j)
                    count += 1
                    continue

                elif recur(lines, i, j, 1, 1, 1, 1, len(lines[0]) - 1, lines[i][j]):
                    print(i, j)
                    count += 1
                else:
                    print("not found")
    print(count)

if __name__ == '__main__':
    main()
