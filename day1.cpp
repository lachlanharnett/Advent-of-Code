#include <array>
#include <cstdio>
#include <iostream>
#include <string>
#include <cwchar>
#include <iterator>
#include <vector>
#include <map>
#include <algorithm>

//int is_empty(const std::string& s) {
//    while (*s != '\0') {
//        if (!isspace((unsigned char)*s))
//            return 0;
//        s++;
//    }
//    return 1;
//}

int main() {

    freopen("../day1.txt","r",stdin);

    std::string test = "fj\n";

//    std::cout << (test[2] == '\n') << std::endl;

    std::vector<int> calories;
    std::string temp;
    while  (std::getline(std::cin, temp)) {
//        std::cout << temp[0] << std::endl;
        if (temp[0] == '\0') {
            calories.push_back('\0');
        } else {
            calories.push_back(stoi(temp));
        }
    }

    int count = 1;
    for (int i : calories) {
        if (i == '\0') {
            count++;
        }
    }

    std::cout << count << std::endl;

    std::vector<std::vector<int>> calories_sum(count, std::vector<int> (2, 0));

    int j = 0;
    calories_sum[0][0] = 1;
    for (int calorie : calories) {
        if (calorie != '\0') {
            calories_sum[j][1] += calorie;
        } else {
            j++;
            calories_sum[j][0] = j + 1;
        }
    }

    std::sort(calories_sum.begin(), calories_sum.end(),
              [](auto const &a, auto const &b) { return a[1] < b[1]; });

    std::cout << calories_sum[234][1] + calories_sum[233][1] + calories_sum[232][1] << std::endl;

}

