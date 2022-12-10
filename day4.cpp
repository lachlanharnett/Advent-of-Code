#include <array>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

int day4() {
    freopen("../day4.txt", "r", stdin);
    std::string compart1;
    std::string compart2;
    int start1;
    int end1;
    int start2;
    int end2;
    std::vector<std::vector<std::string>> groups;

    int count = 0;
    int count2 = 0;
    std::vector<std::string> temp_vec;
    while (std::getline(std::cin, compart2)) {
        int pos = compart2.find(',');
        compart1 = compart2.substr(0, pos);
        std::cout << compart1 << std::endl;
        compart2.erase(0, pos + 1);
        std::cout << compart2 << std::endl;

        int pos2 = compart1.find('-');
//        std::string test = compart1.substr(0,pos2);
//        std::string test2 = compart1.substr(pos2+1);
//        std::cout << test << std::endl;
//        std::cout << test2 << std::endl;
        start1 = std::stoi(compart1.substr(0,pos2));
        end1 = std::stoi(compart1.substr(pos2+1));

        int pos3 = compart2.find('-');
        start2 = std::stoi(compart2.substr(0,pos3));
        end2 = std::stoi(compart2.substr(pos3+1));

        if ((start1 <= start2 && end1 >= end2) || (start1 >= start2 && end1 <= end2)) {
            count++;
        }

        if ((start2 >= start1 && start2 <= end1) || (start1 >= start2 && start1 <= end2)) {
            count2++;
        }
    }

    std::cout << "P1: ";
    std::cout << count << std::endl;
    std::cout << "P2: ";
    std::cout << count2 << std::endl;


}