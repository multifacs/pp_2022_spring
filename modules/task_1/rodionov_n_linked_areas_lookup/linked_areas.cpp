#include "linked_areas.h"
#include <random>

BinaryImage GenerateBinrayImage(int size) {

	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, 1);

	bool** image = new bool* [size];
	for (int x = 0; x < size; x++) {
		image[x] = new bool[size];
		for (int y = 0; y < size; y++) {
			image[x][y] = dist(rng);
		}
	}
	return BinaryImage{image, size};
}






BinaryImageAreas FindAreas(BinaryImage image) {

	BinaryImageAreas areas{};
	areas.size = image.size;
	areas.image = new int* [image.size];
	for (int x = 0; x < image.size; x++) {
		areas.image[x] = new int[image.size];
		for (int y = 0; y < image.size; y++) {
			areas.image[x][y] = -1;
		}
	}

	int label = 0;
	for (int x = 1; x < image.size; x++) {
		for (int y = 1; y < image.size; y++) {
			if (!image.image[x][y])
				continue;

			if (areas.Get(x-1, y) == -1 && areas.Get(x, y-1) == -1) {
				label++;
				areas.image[x][y] = label;
			}
			else if ((areas.Get(x - 1, y) == -1) != (areas.Get(x, y - 1) == -1)) {
				if (areas.Get(x - 1, y) != -1) {
					areas.image[x][y] = areas.Get(x - 1, y);
				}
				else {
					areas.image[x][y] = areas.Get(x, y - 1);
				}
			}
			else if ((areas.Get(x - 1, y) != -1) && (areas.Get(x,y - 1) != -1)) {
				areas.image[x][y] = areas.Get(x, y - 1);
			}
		}
	}
	areas.components = label;
	return areas;
}