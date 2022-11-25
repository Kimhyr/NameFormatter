#include "Formatter.hpp"
#include "Char.hpp"
#include "Text.hpp"
#include <stdio.h>

Bool Formatter::format() {
  if (Char::isAlphabetic(this->peek())) {
    Text buffer;
    Int64 sIndex = this->index;
    do {
      switch (this->state) {
      case Formatter::State::None:
        buffer.put(this->peek());
        break;
      case Formatter::State::Lower:
        this->state = Formatter::State::Upper;
        if (this->peek() != '_') {
          if (Char::isUpper(this->peek())) {
            buffer.put(Char::toLower(this->peek()));
          } else {
            buffer.put(this->peek());
          }
        }
        break;
      case Formatter::State::Upper:
        this->state = Formatter::State::Upper;
        if (this->peek() != '_') {
          if (Char::isLower(this->peek())) {
            buffer.put(Char::toUpper(this->peek()));
          } else {
            buffer.put(this->peek());
          }
        }
        break;
      case Formatter::State::Whisper:
        if (Char::isUpper(this->peek())) {
          buffer.put(Char::toLower(this->peek()));
        } else {
          buffer.put(this->peek());
        }
        break;
      case Formatter::State::Scream:
        if (Char::isLower(this->peek())) {
          buffer.put(Char::toUpper(this->peek()));
        } else {
          buffer.put(this->peek());
        }
        break;
      }
    } while (Char::isAlphabetic(this->peek()) || this->peek() == '_');
    if (buffer.compare("ifndef") == 0) {
      this->state = Formatter::State::Scream;
    } else if (buffer.compare("define") == 0) {
      this->state = Formatter::State::Scream;
    } else if (buffer.compare("struct") == 0) {
      this->state = Formatter::State::Upper;
    }
    printf("%s", buffer.flush());
  }
  return F;
}
