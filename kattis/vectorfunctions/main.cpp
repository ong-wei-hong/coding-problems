#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

void backwards(std::vector<int>& vec) {
    std::reverse(vec.begin(), vec.end());
}

std::vector<int> everyOther(const std::vector<int>& vec) {
    std::vector<int> v((vec.size()+1) / 2);
    for(int i{0}; i < vec.size(); i+=2)
        v[i/2] = vec[i];
    return v;
}

int smallest(const std::vector<int>& vec) {
    return *(std::min_element(vec.begin(), vec.end()));
}

int sum(const std::vector<int>& vec) {
    return std::accumulate(vec.begin(), vec.end(), 0);
}

int veryOdd(const std::vector<int>& vec) {
    int ans {0};
    for(int i {1}; i < vec.size(); i+=2)
        ans += vec[i] % 2;
    return ans;
}

int main() {
    std::vector<int> test = {1, 2, 5, 3, 2, 5};
    std::vector<int> expected = {5, 2, 3, 5, 2, 1};
    backwards(test);
    if (test != expected) {
        std::cerr << "backwards() was incorrect" << std::endl;
        exit(1);
    }

    test = {1, 2, 5, 3, 2, 5};
    expected = {1, 5, 2};
    std::vector<int> got = everyOther(test);
    if (got != expected) {
        std::cerr << "everyOther() was incorrect" << std::endl;
        exit(1);
    }

    test = {1, 2, 5, 3, 2, 5};
    int ans = smallest(test);
    if (ans != 1) {
        std::cerr << "smallest() was incorrect" << std::endl;
        exit(1);
    }

    test = {1, 2, 5, 3, 2, 5};
    ans = sum(test);
    if (ans != 1+2+5+3+2+5) {
        std::cerr << "sum() was incorrect" << std::endl;
        exit(1);
    }

    test = {1, 2, 5, 3, 2, 5};
    ans = veryOdd(test);
    if (ans != 2) {
        std::cerr << "veryOdd() was incorrect" << std::endl;
        exit(1);
    }
    std::cerr << "OK!" << std::endl;
}
