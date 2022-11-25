#pragma once
#ifndef FORMATTER_HPP
#define FORMATTER_HPP

#include "Core.hpp"

struct Formatter {
  Int64 index;
  const Char8 *source;
  enum struct State {
    None,
    Upper,
    Lower,
    Whisper,
    Scream,
  } state;
  
  static constexpr Formatter create(const Char8 *source) {
    return {
        .index = -1,
        .source = source,
        .state = Formatter::State::None,
    };
  }

  Bool format();

  constexpr Char8 peek(Int64 offset = 1) {
    return this->source[this->index + offset];
  }
};

#endif // FORMATTER_HPP
