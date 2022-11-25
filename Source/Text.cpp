#include "Text.hpp"

Text Text::create(UInt64 space) {
  return {
      .space = space,
      .size = 0,
      .buffer = new Char8[space],
  };
}

Void Text::put(Char8 chr) {
  ++this->size;
  if (this->size > this->space) {
    this->space *= 2;
    Char8 *mlock = new Char8[this->space];
    for (UInt64 i = 0; i < this->size; ++i) {
      mlock[i] = this->buffer[i];
    }
    delete[] this->buffer;
    this->buffer = mlock;
  }
  this->buffer[this->size - 1] = chr;
}

Int16 Text::compare(const Char8 *text) {
  const Char8 *bufCmp = this->buffer;
  const Char8 *txtCmp = text;
  while (*bufCmp && (*bufCmp == *txtCmp)) {
    ++bufCmp;
    ++txtCmp;
  }
  return *bufCmp - *txtCmp;
}
