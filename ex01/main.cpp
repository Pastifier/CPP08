#include "Span.hpp"
#include <iostream>
#include <ostream>

#define PRINT(X) std::cout << X
#define FLUSH() std::cout << std::endl

int main() {
  Span sp = Span(11);
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;

  _IntVector vec;
  vec.push_back(1);
  vec.push_back(2);
  vec.push_back(3);
  vec.push_back(4);
  vec.push_back(5);
  vec.end() = vec.end() - (vec.capacity() > 5 ? (vec.capacity() - 5) : 0);
  sp.addRange(vec.begin(), vec.end());

  for (int i = 0; i < 10; ++i) {
    PRINT(sp[i] << (i == 9 ? "" : "\n"));
  }
  FLUSH();
  return 0;
}
