#pragma once

#include <cstddef>
#include <vector>

#define _IntVector std::vector<int>

class Span {
public:
  Span();
  ~Span();
  Span(std::size_t size_);
  Span(Span const &other);
  Span &operator=(Span const &rhs);

  void addNumber(int n_);

  void addRange(_IntVector::iterator __begin, _IntVector::iterator __end);

  int shortestSpan() const;
  int longestSpan() const;

private:
  std::size_t _size;
  std::vector<int> _internal_vec;
};
