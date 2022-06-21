#pragma once
#include "Line.h"

class VerticalLine : public Line {
public:
	VerticalLine(int l) {
		this->length = l;
	}
	void draw() const;
};