#include "easyfind.hpp"
#include <vector>

#define PRINT(X) std::cout << X << "\n"
#define FLUSH() std::cout << std::endl

#define _IntVector std::vector<int>

#define Vector(T) std::vector<T>

int main(void) {
  _IntVector vec1(4);
  vec1.push_back(1);
  vec1.push_back(2);
  vec1.push_back(3);
  vec1.push_back(4);

  _IntVector::const_iterator it = easyfind(vec1, 5);

  if (it == vec1.end())
    ;
  else
    PRINT(*it);
  FLUSH();
  return 0;
}
