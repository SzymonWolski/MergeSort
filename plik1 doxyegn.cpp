#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

/**
 * @class MergeSort
 * @brief Klasa implementująca algorytm sortowania przez scalanie.
 */
class MergeSort {
public:
    /**
     * @brief Sortuje wektor liczb całkowitych za pomocą algorytmu sortowania przez scalanie.
     * @param arr Wektor do posortowania.
     */
    void sort(std::vector<int>& arr);

private:
    /**
     * @brief Rekurencyjnie dzieli tablicę na podtablice i je sortuje.
     * @param arr Wektor do posortowania.
     * @param left Początkowy indeks podtablicy.
     * @param right Końcowy indeks podtablicy.
     */
    void mergeSort(std::vector<int>& arr, int left, int right);

    /**
     * @brief Scala dwie posortowane podtablice w jedną posortowaną tablicę.
     * @param arr Wektor zawierający podtablice.
     * @param left Początkowy indeks pierwszej podtablicy.
     * @param mid Końcowy indeks pierwszej podtablicy.
     * @param right Końcowy indeks drugiej podtablicy.
     */
    void merge(std::vector<int>& arr, int left, int mid, int right);
};

#endif

#include "MergeSort.h"

/**
 * @brief Sortuje podany wektor za pomocą algorytmu sortowania przez scalanie.
 */
void MergeSort::sort(std::vector<int>& arr) {
    mergeSort(arr, 0, arr.size() - 1);
}

/**
 * @brief Rekurencyjnie dzieli tablicę na mniejsze podtablice i je sortuje.
 */
void MergeSort::mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

/**
 * @brief Scala dwie posortowane podtablice w jedną posortowaną tablicę.
 */
void MergeSort::merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> leftArr(n1), rightArr(n2);

    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < n1) {
        arr[k++] = leftArr[i++];
    }

    while (j < n2) {
        arr[k++] = rightArr[j++];
    }
}

#include "MergeSort.h"
#include <iostream>

/**
 * @brief Punkt wejścia do programu MergeSort.
 * Demonstracja użycia klasy MergeSort do sortowania tablicy liczb całkowitych.
 * @return 0 jeśli program zakończył się pomyślnie.
 */
int main() {
    MergeSort sorter;
    std::vector<int> data = { 38, 27, 43, 3, 9, 82, 10 };

    std::cout << "Przed sortowaniem: ";
    for (int num : data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    sorter.sort(data);

    std::cout << "Po sortowaniu: ";
    for (int num : data) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

#include "gtest/gtest.h"

/**
 * @brief Punkt wejścia do uruchamiania testów Google Test.
 * @param argc Liczba argumentów wiersza poleceń.
 * @param argv Tablica argumentów wiersza poleceń.
 * @return Wynik uruchamiania testów.
 */
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#include "gtest/gtest.h"
#include "MergeSort.h"

/**
 * @brief Testuje klasę MergeSort z już posortowanymi danymi.
 */
TEST(MergeSortTest, AlreadySorted) {
    MergeSort sorter;
    std::vector<int> data = {1, 2, 3, 4, 5};
    sorter.sort(data);
    EXPECT_EQ(data, (std::vector<int>{1, 2, 3, 4, 5}));
}

/**
 * @brief Testuje klasę MergeSort z danymi posortowanymi w odwrotnej kolejności.
 */
TEST(MergeSortTest, ReverseSorted) {
    MergeSort sorter;
    std::vector<int> data = {5, 4, 3, 2, 1};
    sorter.sort(data);
    EXPECT_EQ(data, (std::vector<int>{1, 2, 3, 4, 5}));
}

/**
 * @brief Testuje klasę MergeSort z losowymi danymi.
 */
TEST(MergeSortTest, RandomArray) {
    MergeSort sorter;
    std::vector<int> data = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    sorter.sort(data);
    EXPECT_EQ(data, (std::vector<int>{1, 1, 2, 3, 4, 5, 5, 6, 9}));
}

/**
 * @brief Testuje klasę MergeSort z liczbami ujemnymi.
 */
TEST(MergeSortTest, NegativeNumbers) {
    MergeSort sorter;
    std::vector<int> data = {-3, -1, -4, -1, -5};
    sorter.sort(data);
    EXPECT_EQ(data, (std::vector<int>{-5, -4, -3, -1, -1}));
}

/**
 * @brief Testuje klasę MergeSort z mieszanką liczb dodatnich i ujemnych.
 */
TEST(MergeSortTest, MixedNumbers) {
    MergeSort sorter;
    std::vector<int> data = {-3, 1, -4, 0, 5};
    sorter.sort(data);
    EXPECT_EQ(data, (std::vector<int>{-4, -3, 0, 1, 5}));
}

/**
 * @brief Testuje klasę MergeSort z pustą tablicą.
 */
TEST(MergeSortTest, EmptyArray) {
    MergeSort sorter;
    std::vector<int> data;
    sorter.sort(data);
    EXPECT_EQ(data, (std::vector<int>{}));
}

/**
 * @brief Testuje klasę MergeSort z pojedynczym elementem.
 */
TEST(MergeSortTest, SingleElement) {
    MergeSort sorter;
    std::vector<int> data = {1};
    sorter.sort(data);
    EXPECT_EQ(data, (std::vector<int>{1}));
}

/**
 * @brief Testuje klasę MergeSort z duplikatami wartości.
 */
TEST(MergeSortTest, Duplicates) {
    MergeSort sorter;
    std::vector<int> data = {3, 3, 3, 3, 3};
    sorter.sort(data);
    EXPECT_EQ(data, (std::vector<int>{3, 3, 3, 3, 3}));
}

/**
 * @brief Testuje klasę MergeSort z ujemnymi duplikatami wartości.


