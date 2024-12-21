#include "Span.hpp"
#include <algorithm>
#include <climits>
#include <cstddef>
#include <cstdlib>
#include <iterator>
#include <stdexcept>
#include <vector>

Span::Span() : _size(1), _internal_vec() { _internal_vec.reserve(1); }
Span::Span(std::size_t size_) : _size(size_), _internal_vec() {
  _internal_vec.reserve(size_);
}

Span::Span(Span const &other)
    : _size(other._size), _internal_vec(std::vector<int>(other._internal_vec)) {
}

Span::~Span() {}

Span &Span::operator=(Span const &rhs) {
  if (this != &rhs) {
    _size = rhs._size;
    _internal_vec = rhs._internal_vec;
  }
  return *this;
}

void Span::addNumber(int n_) {
  if (_internal_vec.size() == _size)
    throw std::out_of_range("Error: Can't allocate past predetermined size.");
  _internal_vec.push_back(n_);
}

int Span::shortestSpan() const {
  if (_internal_vec.empty() || _internal_vec.size() == 1)
    throw std::length_error(
        "Error: Can't find shortest span in insufficient-length Span");

  _IntVector _copy(_internal_vec);
  _IntVector::const_iterator prevIt = _copy.begin();
  std::sort(_copy.begin(), _copy.end());

  int span = INT_MAX;

  for (_IntVector::const_iterator it = prevIt + 1; it != _copy.end(); ++it) {
    int diff = std::abs(*it - *prevIt);

    if (diff <= span)
      span = diff;

    prevIt = it;
  }
  return span;
}

int Span::longestSpan() const {
  if (_internal_vec.empty() || _internal_vec.size() == 1)
    throw std::length_error(
        "Error: Can't find longest span in insufficient-length Span");

  _IntVector _copy(_internal_vec);

  int span = *(std::max_element(_copy.begin(), _copy.end())) -
             *(std::min_element(_copy.begin(), _copy.end()));
  return span;
}

void Span::addRange(_IntVector::iterator __begin, _IntVector::iterator __end) {
  if (_internal_vec.size() + std::distance(__begin, __end) > _size)
    throw std::out_of_range(
        "Error: Adding range conflicts with predetermined Span size");
  _internal_vec.insert(_internal_vec.begin(), __begin, __end);
}
