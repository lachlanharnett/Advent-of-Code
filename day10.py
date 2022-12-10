
def main():
    f = open("./day10.txt", "r")
    lines = f.readlines()
    lines = [row.rstrip() for row in lines]

    sum = 0
    x = 1
    cycle = 1
    last = 0
    instr = []
    count = 0
    # for j in range(len(lines)):
    #     instr = lines[j].split(" ")
    #     if instr[0] == "addx":
    #         count += 2
    #     else:
    #         count += 1
    # print(count)

    i = 0
    row = "#"
    while i < len(lines):
        # if cycle == 1 and (x - 1 == 0 or x == 0 or x + 1 == 0):
        #     row += "#"
        # else:
        #     row += "."
        instr = lines[i].split(" ")
        if len(instr) != 1:
            last = int(instr[1])
            x += last
            cycle += 1
            if x - 1 == (cycle % 40) or x == (cycle % 40) or x + 1 == (cycle % 40):
                row += "#"
            else:
                row += "."
            # print(cycle, x)
            if cycle == 20 or (cycle + 20) % 40 == 0:
                sum += (x * cycle)
                # print(sum, x)
            if cycle % 40 == 0:
                print(row)
                row = ""
        i += 1
        cycle += 1
        # print(cycle, x)
        if x - 1 == (cycle % 40) or x == (cycle % 40) or x + 1 == (cycle % 40):
            row += "#"
        else:
            row += "."
        if cycle == 20 or (cycle + 20) % 40 == 0:
            sum += (x * cycle)
            # print(sum, x)
        if cycle % 40 == 0:
            print(row)
            row = ""
    print(sum)

if __name__ == '__main__':
    main()
