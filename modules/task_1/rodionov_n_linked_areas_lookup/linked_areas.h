#include <cstdlib>

struct BinaryImage {
	bool** image;
	int size;

	bool Get(int a, int b) {
		if (a < 0 || b < 0 || a >= size || b >= size) {
			return false;
		}
		return image[a][b];
	}
	~BinaryImage() {
		for (int x = 0; x < size; x++) {
			delete[] image[x];
		}
		delete[] image;
	}
};

struct BinaryImageAreas {
	int components;
	int** image;
	int size;

	int Get(int a, int b) {
		if (a < 0 || b < 0 || a >= size || b >= size) {
			return -1;
		}
		return image[a][b];
	}
	~BinaryImageAreas() {
		for (int x = 0; x < size; x++) {
			delete[] image[x];
		}
		delete[] image;
	}

};


BinaryImage GenerateBinrayImage(int size);

BinaryImageAreas FindAreas(BinaryImage image);

void show(BinaryImageAreas image);