#pragma once
#include "Line.h"

class HorizontalLine : public Line {
public:
	HorizontalLine(int l) {
		this->length = l;
	}
	void draw() const;
};