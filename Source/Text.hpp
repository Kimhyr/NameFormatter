#pragma once
#ifndef TEXT_HPP
#define TEXT_HPP

#include "Core.hpp"

struct Text {
	UInt64 space;
	UInt64 size;
	Char8 *buffer;
	
	static  Text create(UInt64 space = 2);
	
	constexpr const Char8 *flush() {
		return this->buffer;
	}
	
	Void put(Char8 chr);

	Int16 compare(const Char8 *text);
};

#endif  // TEXT_HPP
