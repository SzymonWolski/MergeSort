//
// pch.h
//

#pragma once

#include "gtest/gtest.h"
#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

class MergeSort {
public:
    void sort(std::vector<int>& arr);

private:
    void mergeSort(std::vector<int>& arr, int left, int right);
    void merge(std::vector<int>& arr, int left, int mid, int right);
};

#endif