#include <iostream>
#include <fstream>

int day6() {

    std::string data;
    std::ifstream file;
    file.open("../day6.txt");
    std::getline(file, data);
    int result = -1;
    int window = 13;
    int k = 0;
    int l = 0;

    for (int i = 0; i < data.size(); i++) {
        for (k = 0; k < window; k++) {
            for (l = k; l < window; l++) {
                std::cout << data[i+window - k];
                std::cout << i+window - k;
                std::cout << data[i+window - l - 1];
                std::cout << i+window - l - 1 << std::endl;
                if (data[i + window - k] == data[i + window - l - 1]) {
                    goto multi_break;
                }
            }
        }
        result = i + window + 1;
        break;

        multi_break:
        std::cout << l << std::endl;
        i += (window - l - 1);
    }

    file.close();

    std::cout << result << std::endl;
}
