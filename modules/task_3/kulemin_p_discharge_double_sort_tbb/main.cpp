    // Copyright 2018 Nesterov Alexander
#include <gtest/gtest.h>
#include <vector>
#include "./kulemin_p_discharge_double_sort_tbb.h"

TEST(Parallel_Operations_OpenMP, Test_No_Throw) {
    vector* vb;
    vb = create_random_vector(10);
    ASSERT_NO_THROW(discharge_sort(vb));
}

TEST(Parallel_Operations_OpenMP, Test_100000) {
    int count = 100000;
    vector* vb = create_random_vector(count);
    vector* sd = new vector(count);
    copy_vectors(vb->ptr, sd->ptr, count);
	tbb::tick_count start_seq = tbb::tick_count::now();
	discharge_sort_seq(vb);
	tbb::tick_count end_seq = tbb::tick_count::now();
	double sequential_runtime = (end_seq - start_seq).seconds();
	tbb::tick_count start_tbb = tbb::tick_count::now();
    discharge_sort(sd);
	tbb::tick_count end_tbb = tbb::tick_count::now();
	double parallel_tbb_runtime = (end_tbb - start_tbb).seconds();
	std::cout << "sequential_runtime = " << sequential_runtime << std::endl;
	std::cout << "parallel_tbb_runtime = " << parallel_tbb_runtime
		<< std::endl;
	std::cout << "a = " << sequential_runtime / parallel_tbb_runtime << "\n";
    bool res = check_vectors(vb->ptr, sd->ptr, count);
    ASSERT_EQ(true, res);
}


TEST(Parallel_Operations_OpenMP, Test_150000) {
	int count = 150000;
	vector* vb = create_random_vector(count);
	vector* sd = new vector(count);
	copy_vectors(vb->ptr, sd->ptr, count);
	tbb::tick_count start_seq = tbb::tick_count::now();
	discharge_sort_seq(vb);
	tbb::tick_count end_seq = tbb::tick_count::now();
	double sequential_runtime = (end_seq - start_seq).seconds();
	tbb::tick_count start_tbb = tbb::tick_count::now();
	discharge_sort(sd);
	tbb::tick_count end_tbb = tbb::tick_count::now();
	double parallel_tbb_runtime = (end_tbb - start_tbb).seconds();
	std::cout << "sequential_runtime = " << sequential_runtime << std::endl;
	std::cout << "parallel_tbb_runtime = " << parallel_tbb_runtime
		<< std::endl;
	std::cout << "a = " << sequential_runtime / parallel_tbb_runtime << "\n";
	bool res = check_vectors(vb->ptr, sd->ptr, count);
	ASSERT_EQ(true, res);
}
TEST(Parallel_Operations_OpenMP, Test_200000) {
	int count = 200000;
	vector* vb = create_random_vector(count);
	vector* sd = new vector(count);
	copy_vectors(vb->ptr, sd->ptr, count);
	tbb::tick_count start_seq = tbb::tick_count::now();
	discharge_sort_seq(vb);
	tbb::tick_count end_seq = tbb::tick_count::now();
	double sequential_runtime = (end_seq - start_seq).seconds();
	tbb::tick_count start_tbb = tbb::tick_count::now();
	discharge_sort(sd);
	tbb::tick_count end_tbb = tbb::tick_count::now();
	double parallel_tbb_runtime = (end_tbb - start_tbb).seconds();
	std::cout << "sequential_runtime = " << sequential_runtime << std::endl;
	std::cout << "parallel_tbb_runtime = " << parallel_tbb_runtime
		<< std::endl;
	std::cout << "a = " << sequential_runtime / parallel_tbb_runtime << "\n";
	bool res = check_vectors(vb->ptr, sd->ptr, count);
	ASSERT_EQ(true, res);
}
TEST(Parallel_Operations_OpenMP, Test_400000) {
	int count = 400000;
	vector* vb = create_random_vector(count);
	vector* sd = new vector(count);
	copy_vectors(vb->ptr, sd->ptr, count);
	tbb::tick_count start_seq = tbb::tick_count::now();
	discharge_sort_seq(vb);
	tbb::tick_count end_seq = tbb::tick_count::now();
	double sequential_runtime = (end_seq - start_seq).seconds();
	tbb::tick_count start_tbb = tbb::tick_count::now();
	discharge_sort(sd);
	tbb::tick_count end_tbb = tbb::tick_count::now();
	double parallel_tbb_runtime = (end_tbb - start_tbb).seconds();
	std::cout << "sequential_runtime = " << sequential_runtime << std::endl;
	std::cout << "parallel_tbb_runtime = " << parallel_tbb_runtime
		<< std::endl;
	std::cout << "a = " << sequential_runtime / parallel_tbb_runtime << "\n";
	bool res = check_vectors(vb->ptr, sd->ptr, count);
	ASSERT_EQ(true, res);
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
