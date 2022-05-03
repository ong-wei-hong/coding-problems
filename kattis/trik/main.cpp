#include <iostream>
#include <string>

int main() {
    int ball {1};

    std::string moves {};
    std::cin >> moves;

    for(char c: moves) {
        switch(c) {
            case 'A':
                if (ball == 1)
                    ball = 2;
                else if(ball == 2)
                    ball = 1;
                break;
            case 'B':
                if (ball == 2)
                    ball = 3;
                else if(ball == 3)
                    ball = 2;
                break;
            case 'C':
                if (ball == 1)
                    ball = 3;
                else if(ball == 3)
                    ball = 1;
                break;
        }
    }
    std::cout << ball << '\n';
    return 0;
}