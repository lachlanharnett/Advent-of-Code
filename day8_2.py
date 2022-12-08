def recur(lines, i, j, up, left, down, right, line_len, orig_tree):
    current = lines[i][j]
    results = []
    print([i, j, up, left, down, right])
    if up and down and left and right:
        results.append(recur(lines, i - 1, j, 1, 0, 0, 0, line_len, orig_tree) + 1)
        print(results)
        result = (recur(lines, i, j - 1, 0, 1, 0, 0, line_len, orig_tree) + 1)
        print(result)
        results.append(result)
        print(results)
        results.append(recur(lines, i + 1, j, 0, 0, 1, 0, line_len, orig_tree) + 1)
        print(results)
        results.append(recur(lines, i, j + 1, 0, 0, 0, 1, line_len, orig_tree) + 1)
        print(results)
        return results[0] * results[1] * results[2] * results[3]
    else:
        if i * j == 0 or i == line_len or j == line_len:
            print("test")
            return 0
        elif up and orig_tree > lines[i][j]: # and lines[i - 1][j] <= current:
            if i - 1 == 0:
                return 1
            else:
                return recur(lines, i - 1, j, 1, 0, 0, 0, line_len, orig_tree) + 1
            # current = lines[i + 1][j]
        elif left and orig_tree > lines[i][j]: # and lines[i][j - 1] <= current:
            if j - 1 == 0:
                return 1
            else:
                return recur(lines, i, j - 1, 0, 1, 0, 0, line_len, orig_tree) + 1
            # current = lines[i][j + 1]
        elif down and orig_tree > lines[i][j]: # and lines[i + 1][j] <= current:
            print(orig_tree, i+1,j, lines[i + 1][j])
            if i + 1 == line_len:
                return 1
            else:
                return recur(lines, i + 1, j, 0, 0, 1, 0, line_len, orig_tree) + 1
            # current = lines[i - 1][j]
        elif right and orig_tree > lines[i][j]: # and lines[i][j + 1] <= current:
            if j + 1 == line_len:
                return 1
            else:
                return recur(lines, i, j + 1, 0, 0, 0, 1, line_len, orig_tree) + 1
        # current = lines[i][j - 1]
    # print("orig_tree")
    # print("Orig_tree: " + orig_tree)
    return 0



def main():
    f = open("./day8.txt", "r")
    lines = f.readlines()
    lines = [row.rstrip() for row in lines]
    line_len = len(lines)
    view_dist = [ [0]*line_len for x in range(line_len)]

    max_dist = 0
    dist_coords = None

    for i in range(line_len):
        for j in range(len(lines[i])):
            # print(len(lines[0]) - 1)
            if i * j == 0 or i == line_len - 1 or j == line_len - 1:
                view_dist[i][j] = 0
            else:
                view_dist[i][j] = recur(lines, i, j, 1, 1, 1, 1, line_len - 1, lines[i][j])

            if view_dist[i][j] > max_dist:
                max_dist = view_dist[i][j]
                dist_coords = [i, j]
            print(i, j)
    print(max_dist)
    print(dist_coords)

if __name__ == '__main__':
    main()