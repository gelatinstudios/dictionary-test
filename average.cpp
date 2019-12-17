
#include <iostream>
#include <fstream>
#include <string>

struct average {
        double av;
        size_t count;
};

average f(const std::string n) {
        average av;
        std::ifstream file(n);
        std::string line;
        av.count = 0;
        double sum = 0.0;
        while(getline(file, line)) {
                sum += stod(line);
                ++av.count;
        }
        file.close();
        av.av = sum / av.count;
        return av;
}

int main() {
        const average dict = f("dict.txt");
        const average mike = f("mike.txt");
        std::cout << "dict: " << dict.av << "\t";
        std::cout << "count: " << dict.count << "\n";
        std::cout << "mike: " << mike.av << "\t";
        std::cout << "count: " << mike.count << "\n";
}
