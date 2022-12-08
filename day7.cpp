//
// Created by Lachlan on 7/12/2022.
//

#include <iostream>
#include <string>
#include <regex>
#include <tuple>


struct Node {
    int key;
    std::vector<Node*> children;
};

int day7() {

    freopen("../day7.txt", "r", stdin);
    std::vector<std::string> lines;
    std::string line;
    std::string compara = "$ ls";
    std::regex mv_dir("\\$ cd [^\\.]*");
    std::vector<std::tuple<std::string, int, int>> directories;
    std::string path;
    int po_idx = 0;


    while (std::getline(std::cin, line)) {
        if (line[0] == '\0') {
            lines.emplace_back("\0");
        } else {
            lines.push_back(line);
        }
    }

    int i = 0;
    while (i < lines.size()) {
//        std::cout << po_idx << std::endl;
        if (regex_match(lines[i], mv_dir)) {
//            std::cout << lines[i] + " match" << std::endl;
            std::string temp = lines[i].substr(5, lines[i].length());
            path += temp + '/';
            directories.emplace_back(path, 0, 0);
//            std::cout << lines[i] << std::endl;
            po_idx++;
            i++;
        } else {
//            std::cout << lines[i] + " mismatch" << std::endl;
            int pos = path.find_last_of('/');
            path.erase(pos, std::string::npos);
            pos = path.find_last_of('/');
            path = path.erase(pos + 1, std::string::npos);
//            std::cout << pos << std::endl;
            i++;
        }

        if (lines[i] == compara) {
//            std::cout << lines[i] << std::endl;
            i++;
            while (i < lines.size() && lines[i][0] != '$') {
                //int pos= line.find(' ');
                std::string temp = lines[i].substr(0, lines[i].find(' '));
                lines[i].erase(0, lines[i].find(' ') + 1);
//                std::cout << lines[i];
//                std::cout << temp << std::endl;
                if (temp != "dir") {
//                    std::cout << lines[i];
//                    std::cout << temp << std::endl;
//                    std::cout << std::get<1>(directories[po_idx - 1]) << std::endl;
                    std::get<1>(directories[po_idx - 1]) += stoi(temp);
                }

                else {
                    std::get<2>(directories[po_idx - 1])++;
                }
                i++;
            }
        }
    }


    Node* root = new Node();
    std::vector<Node*> temp;
    root->children = temp;
    root->key = std::get<1>(directories[0]);
    Node* temp_node = root;

    for (int f = 1; i < directories.size(); f++) {
//        std::cout << std::get<0>(directory) + " ";
//        std::cout << std::get<1>(directory);
//        std::cout << " ";
//        std::cout << std::get<2>(directory) << std::endl;

        temp_node->children.push_back(new Node());
        temp_node = temp_node->children[f];
        temp_node->key = std::get<1>(directories[f]);
    }

}