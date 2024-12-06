#include "gtest/gtest.h"
#include "MergeSort.h"

TEST(MergeSortTest, AlreadySorted) {
    MergeSort sorter;
    std::vector<int> data = {1, 2, 3, 4, 5};
    sorter.sort(data);
    EXPECT_EQ(data, (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(MergeSortTest, ReverseSorted) {
    MergeSort sorter;
    std::vector<int> data = {5, 4, 3, 2, 1};
    sorter.sort(data);
    EXPECT_EQ(data, (std::vector<int>{1, 2, 3, 4, 5}));
}

TEST(MergeSortTest, RandomArray) {
    MergeSort sorter;
    std::vector<int> data = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    sorter.sort(data);
    EXPECT_EQ(data, (std::vector<int>{1, 1, 2, 3, 4, 5, 5, 6, 9}));
}

TEST(MergeSortTest, NegativeNumbers) {
    MergeSort sorter;
    std::vector<int> data = {-3, -1, -4, -1, -5};
    sorter.sort(data);
    EXPECT_EQ(data, (std::vector<int>{-5, -4, -3, -1, -1}));
}

TEST(MergeSortTest, MixedNumbers) {
    MergeSort sorter;
    std::vector<int> data = {-3, 1, -4, 0, 5};
    sorter.sort(data);
    EXPECT_EQ(data, (std::vector<int>{-4, -3, 0, 1, 5}));
}

TEST(MergeSortTest, EmptyArray) {
    MergeSort sorter;
    std::vector<int> data;
    sorter.sort(data);
    EXPECT_EQ(data, (std::vector<int>{}));
}

TEST(MergeSortTest, SingleElement) {
    MergeSort sorter;
    std::vector<int> data = {1};
    sorter.sort(data);
    EXPECT_EQ(data, (std::vector<int>{1}));
}

TEST(MergeSortTest, Duplicates) {
    MergeSort sorter;
    std::vector<int> data = {3, 3, 3, 3, 3};
    sorter.sort(data);
    EXPECT_EQ(data, (std::vector<int>{3, 3, 3, 3, 3}));
}

TEST(MergeSortTest, NegativeDuplicates) {
    MergeSort sorter;
    std::vector<int> data = {-3, -3, -3, -3, -3};
    sorter.sort(data);
    EXPECT_EQ(data, (std::vector<int>{-3, -3, -3, -3, -3}));
}

TEST(MergeSortTest, TwoElements) {
    MergeSort sorter;
    std::vector<int> data = {2, 1};
    sorter.sort(data);
    EXPECT_EQ(data, (std::vector<int>{1, 2}));
}

TEST(MergeSortTest, LargeArray) {
    MergeSort sorter;
    std::vector<int> data(150);
    for (int i = 0; i < 150; ++i) {
        data[i] = 150 - i;
    }
    sorter.sort(data);

    std::vector<int> expected(150);
    for (int i = 0; i < 150; ++i) {
        expected[i] = i + 1;
    }
    EXPECT_EQ(data, expected);
}

TEST(MergeSortTest, LargeArrayWithMixedNumbers) {
    MergeSort sorter;
    std::vector<int> data(150);
    for (int i = 0; i < 150; ++i) {
        data[i] = (i % 2 == 0 ? i : -i);
    }
    sorter.sort(data);

    std::vector<int> expected(150);
    for (int i = 0; i < 75; ++i) {
        expected[i] = -149 + i * 2;
        expected[75 + i] = i * 2;
    }
    EXPECT_EQ(data, expected);
}