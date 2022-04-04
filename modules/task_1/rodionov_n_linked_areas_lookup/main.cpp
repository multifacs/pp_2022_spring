#include <iostream>
#include <cstdio>
#include "linked_areas.h"


int main() {
	BinaryImage image = GenerateBinrayImage(600);
	BinaryImageAreas areas = FindAreas(image);
	show(areas);
	return 0;
}