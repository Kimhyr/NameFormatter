#pragma once
#ifndef CHAR_HPP
#define CHAR_HPP

#include "Core.hpp"

struct Char {
  static constexpr Bool isLower(Char8 chr) {
    return chr >= 'a' && chr <= 'z';
  }
  
  static constexpr Bool isUpper(Char8 chr) {
    return chr >= 'A' && chr <= 'Z';
  }
  
  static constexpr Bool isAlphabetic(Char8 chr) {
    return Char::isLower(chr) || Char::isUpper(chr);
  }
  
  static constexpr Char8 toUpper(Char8 chr) {
    if (!Char::isLower(chr)) {
      return 0;
    }
    return chr + 32;
  }
  
  static constexpr Char8 toLower(Char8 chr) {
    if (!Char::isUpper(chr)) {
      return 0;
    }
    return chr - 32;
  }
};

#endif // CHAR_HPP
