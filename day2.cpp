#include <array>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

int day2() {
    freopen("../day2.txt", "r", stdin);
    int result1 = 0;
    int result2 = 0;
    std::string temp;

    std::map<std::string, int> options1 = {
            { "A X", 4 },
            { "A Y", 8 },
            { "A Z", 3 },
            { "B X", 1 },
            { "B Y", 5 },
            { "B Z", 9 },
            { "C X", 7 },
            { "C Y", 2 },
            { "C Z", 6 }
    };

    std::map<std::string, int> options2 = {
            { "A X", 3 },
            { "A Y", 4 },
            { "A Z", 8 },
            { "B X", 1 },
            { "B Y", 5 },
            { "B Z", 9 },
            { "C X", 2 },
            { "C Y", 6 },
            { "C Z", 7 }
    };

    while (std::getline(std::cin, temp)) {
        result1 += options1[temp];
        result2 += options2[temp];
//        printf(temp);
    }
    printf("P1: %i\n", result1);
    printf("P2: %i\n", result2);
}