//
// Created by Lachlan on 7/12/2022.
//

#include <iostream>
#include <string>
#include <regex>
#include <tuple>

int smallfiles = 0;
int small_size = 0;

struct Node {
    int key{};
    std::vector<Node> children;
};

int create_tree(std::vector<std::tuple<std::string, int, int>> directories, Node* root) {
    int depth = std::get<2>(directories[0]);
    if (directories.size() == 1 || depth + 1 != std::get<2>(directories[1])) {
        if (root->key <= 100000) {
            smallfiles++;
            small_size += root->key;
        }
        return std::get<1>(directories[0]);
    }
    directories.erase(directories.begin());
    int i = 0;
//    std::cout << depth << std::endl;
//    std::cout << std::get<2>(directories[i]) << std::endl;

    while (depth + 1 == std::get<2>(directories[i])) {
        Node new_node = Node();
        new_node.key = std::get<1>(directories[i]);
        new_node.children = std::vector<Node>();
        root->children.push_back(new_node);
        root->key += create_tree(directories, &new_node);
        i++;
    }
    if (root->key <= 100000) {
        smallfiles++;
        small_size += root->key;
    }

}

int day7() {

    freopen("../day7.txt", "r", stdin);
    std::vector<std::string> lines;
    std::string line;
    std::string compara = "$ ls";
    std::regex mv_dir("\\$ cd [^\\.]*");
    std::vector<std::tuple<std::string, int, int>> directories;
    std::string path;
    int po_idx = 0;
    int depth = 0;

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
//        std::cout << lines[i] << std::endl;
        if (regex_match(lines[i], mv_dir)) {
//            std::cout << lines[i] + " match" << std::endl;
            std::string temp = lines[i].substr(5, lines[i].length());
            path += temp + '/';
            directories.emplace_back(std::make_tuple(path, 0, 0));
//            std::cout << lines[i] << std::endl;
            po_idx++;
            i++;
            depth++;
            std::get<2>(directories[po_idx - 1]) = depth;
        } else {
//            std::cout << lines[i] + " mismatch" << std::endl;
            int pos = path.find_last_of('/');
            path.erase(pos, std::string::npos);
            pos = path.find_last_of('/');
            path = path.erase(pos + 1, std::string::npos);
//            std::cout << pos << std::endl;
            i++;
            depth--;
            continue;
        }
//
//        std::cout << lines[i] << std::endl;
        if (lines[i] == compara) {
//            std::cout << lines[i] << std::endl;
            i++;
            while (i < lines.size() && lines[i][0] != '$') {
                //int pos= line.find(' ');
                std::string temp = lines[i].substr(0, lines[i].find(' '));
                lines[i].erase(0, lines[i].find(' ') + 1);
//                std::cout << lines[i] + " ";
//                std::cout << temp << std::endl;
                if (temp != "dir") {
//                    std::cout << lines[i];
//                    std::cout << temp << std::endl;
//                    std::cout << std::get<1>(directories[po_idx - 1]) << std::endl;
                    std::get<1>(directories[po_idx - 1]) += stoi(temp);
                }

//                else {
//                    std::get<2>(directories[po_idx - 1]) = depth;
//                }
                i++;
            }
        }
    }

    for (int f = 0; f < directories.size(); f++) {
//        std::cout << f << std::endl;
        std::cout << std::get<0>(directories[f]) + " ";
        std::cout << std::get<1>(directories[f]);
        std::cout << " ";
        std::cout << std::get<2>(directories[f]) << std::endl;
    }

    Node root = Node();
    int final  = create_tree(directories, &root);
//    std::cout << final << std::endl;
    std::cout << smallfiles << std::endl;
    std::cout << small_size << std::endl;
//    int max_depth = 0;
//
//    for (int f = 1; f < directories.size(); f++) {
//        std::cout << f << std::endl;
//        std::cout << std::get<0>(directories[f]) + " ";
//        std::cout << std::get<1>(directories[f]);
//        std::cout << " ";
//        std::cout << std::get<2>(directories[f]) << std::endl;
//
//        temp_node.children.push_back(Node());
//        temp_node = temp_node.children[0];
//        temp_node.key = std::get<1>(directories[f]);
//    }

}
