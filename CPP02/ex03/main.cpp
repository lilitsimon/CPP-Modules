#include "Point.hpp"
#include "bsp.hpp"
#include <iostream>

int main() {
    Point a(0, 0);
    Point b(10, 0);
    Point c(5, 10);

    Point inside(5, 5);
    Point outside(10, 10);
    Point edge(5, 0);
    Point vertex(0, 0);

    std::cout << "Point inside: " << bsp(a, b, c, inside) << std::endl;
    std::cout << "Point outside: " << bsp(a, b, c, outside) << std::endl;
    std::cout << "Point on edge: " << bsp(a, b, c, edge) << std::endl;
    std::cout << "Point on vertex: " << bsp(a, b, c, vertex) << std::endl;

    return 0;
}
