#include <iostream>
#include <cstdio>
#include "linked_areas.h"
#include <gtest/gtest.h>
#include <gtest-mpi-listener.hpp>


const int IMAGE_SIZE = 500;






TEST(LinkedAreasLookup, GenerateBinaryImageTest) {
	BinaryImage image = GenerateBinrayImage(IMAGE_SIZE);

	ASSERT_EQ(image.size, IMAGE_SIZE);
	
	// Try to read all values, to check wheter array is okay
	for (int x = 0; x < image.size; x++) 
		for (int y = 0; y < image.size; y++) 
			bool val = image.Get(x, y);
}

TEST(LinkedAreasLookup, GenerateBinaryImageDestroyTest) {
	BinaryImage image = GenerateBinrayImage(IMAGE_SIZE);
	image.~BinaryImage();
}


TEST(LinkedAreasLookup, FindAreasTest) {
	BinaryImage image = GenerateBinrayImage(IMAGE_SIZE);
	BinaryImageAreas areas = FindAreas(image);

	// Try to read all values, to check wheter array is okay
	for (int x = 0; x < areas.size; x++)
		for (int y = 0; y < areas.size; y++)
			int val = areas.Get(x, y);
}

TEST(LinkedAreasLookup, FindAreasDestroyTest) {
	BinaryImage image = GenerateBinrayImage(IMAGE_SIZE);
	BinaryImageAreas areas = FindAreas(image);
	image.~BinaryImage();
	areas.~BinaryImageAreas();

}


int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	::testing::AddGlobalTestEnvironment(new GTestMPIListener::MPIEnvironment);
	::testing::TestEventListeners& listeners =
		::testing::UnitTest::GetInstance()->listeners();

	listeners.Release(listeners.default_result_printer());
	listeners.Release(listeners.default_xml_generator());

	listeners.Append(new GTestMPIListener::MPIMinimalistPrinter);

	return RUN_ALL_TESTS();
}