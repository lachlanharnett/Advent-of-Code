#include <array>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

int day3() {
    freopen("../day3.txt", "r", stdin);
    std::string compart1;
    std::string compart2;
    std::vector<std::vector<std::string>> groups;

    int pcount = 0;
    int read = 1;
    std::vector<std::string> temp_vec;
    while (std::getline(std::cin, compart2)) {
//        std::cout << compart2 << std::endl;
        if (read % 3 != 0) {
            temp_vec.push_back(compart2);
        } else {
            temp_vec.push_back(compart2);
            groups.push_back(temp_vec);
            temp_vec = std::vector<std::string>();
        }
        read++;

        int total_len = compart2.length();
        int half_pos = total_len / 2;
        compart1 = compart2.substr(0, half_pos);
        compart2.erase(0, half_pos);
//        std::cout << compart1 << std::endl;
//        std::cout << compart2 << std::endl;
        for (char left : compart1) {
            // TODO Improve search
            for (char right : compart2) {
                if (left == right) {
//                    std::cout << left << std::endl;
                    if (isupper(left)) {
                        pcount += int(tolower(left)) - 70;
                    } else {
                        pcount += int(toupper(left)) - 64;
                    }
                    goto next;
                }
            }
        }

        next:
        continue;
    }

    int badge_pcount = 0;
    for (std::vector<std::string> group : groups) {
        std::vector<std::set<char>> distinct;
        std::vector<char> concat;
        for (int i = 0; i < group.size(); i++) {
            std::set<char> temp_set;
            distinct.emplace_back(temp_set);
            std::string contents = group[i];
//            std::cout << i << std::endl;
            std::cout << contents << std::endl;
            for (char item : contents) {
                if (std::count(contents.begin(), contents.end(), item) > 0) {
                    distinct[i].insert(item);
                }
            }
            concat.insert(concat.end(),distinct[i].begin(), distinct[i].end());
        }

        for (char unique : concat) {
            std::cout << unique;
            if (std::count(concat.begin(), concat.end(), unique) == group.size()) {

                if (isupper(unique)) {
                    badge_pcount += int(tolower(unique)) - 70;
                } else {
                    badge_pcount += int(toupper(unique)) - 64;
                }
                std::cout << std::endl;
                std::cout << unique << std::endl;
                break;
            }
        }
        std::cout << std::endl;
    }

    std::cout << "P1: ";
    std::cout << pcount << std::endl;
    std::cout << "P2: ";
    std::cout << badge_pcount << std::endl;

}

//    std::set<char> distinct;
//    std::vector<char> dupes;
//    for (std::vector<std::string> group : groups) {
//        for (int i = 0; i < group.size(); i++) {
//            std::string contents = group[i];
//            for (char item : contents) {
//                auto in = distinct.find(item);
//                if (i == 0) {
//                    if (in == distinct.end()) {
//                        distinct.insert(item);
//                    } else {
//                        dupes.push_back(item);
//                    }
//                } else if (i > 0  && ) {
//
//                }
//            }
//            if (i == 0) {
//
//            }
//        }
//    }
