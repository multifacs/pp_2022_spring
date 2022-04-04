#include <iostream>
#include "linked_areas.h"


int main() {
	BinaryImage image = GenerateBinrayImage(20);
	BinaryImageAreas areas = FindAreas(image);

	return 0;
}