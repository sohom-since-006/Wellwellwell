#include <iostream>

void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 0) return;
    towerOfHanoi(n - 1, from, aux, to);
    std::cout << "Move disk " << n << " from " << from << " to " << to << "\n";
    towerOfHanoi(n - 1, aux, to, from);
}

int main() {
    std::cout << "Hanoi solution for 3 disks:\n";
    towerOfHanoi(3, 'A', 'C', 'B');
    return 0;
}
