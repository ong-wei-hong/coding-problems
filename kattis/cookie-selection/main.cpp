#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

std::string s;
std::priority_queue<int> max;
std::priority_queue<int, std::vector<int>, std::greater<int>> min;

int main() {
    while(std::cin >> s) {
        if(s == "#"){
            std::cout << min.top() << '\n';
            min.pop();
        } else {
            int i {std::stoi(s)};
            if((!min.empty()) && i > min.top())
                min.push(i);
            else 
                max.push(i);
        }

        if(min.size() > max.size() + 1) {
            max.push(min.top());
            min.pop();
        } else if(min.size() < max.size()) {
            min.push(max.top());
            max.pop();
        }
    }

    return 0;
}