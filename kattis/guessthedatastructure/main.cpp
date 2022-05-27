#include <iostream>
#include <queue>
#include <stack>
#include <vector>

int n, x, y, i;
bool q, p, s;

std::queue<int>          queue;
std::priority_queue<int> priority_queue;
std::stack<int>          stack;

int main() {
    while(std::cin >> n) {
        while(!queue.empty()) queue.pop();
        while(!priority_queue.empty()) priority_queue.pop();
        while(!stack.empty()) stack.pop();
        q = p = s = true;

        while(n--) {
            std::cin >> x >> y;
            if(x == 1) {
                queue.push(y);
                priority_queue.push(y);
                stack.push(y);
            } else if (x == 2) {
                if(queue.size()){
                    q = q && (queue.front() == y);
                    queue.pop();
                    p = p && (priority_queue.top() == y);
                    priority_queue.pop();
                    s = s && (stack.top() == y);
                    stack.pop();
                } else
                    p = q = s = false;
            }
        }

        i = p + q + s;
        if(i == 0)
            std::cout << "impossible\n";
        else if(i > 1)
            std::cout << "not sure\n";
        else if(p)
            std::cout << "priority queue\n";
        else if(q)
            std::cout << "queue\n";
        else if(s)
            std::cout << "stack\n";
    }
    return 0;
}