#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <sys/time.h>
#include <iomanip>
#include <cstddef>

bool isValid(const char *str);
void readInput(std::vector<int> &vec, std::deque<int> &deq, int argc, char **argv);
void mergeInsertionSortVector(std::vector<int> &vec, int start, int end);
void insertionSortVector(std::vector<int> &vec, int start, int end);
void mergeSortVector(std::vector<int> &vec, int start, int mid, int end);
void mergeInsertionSortDeque(std::deque<int> &deq, int start, int end);
void insertionSortDeque(std::deque<int> &deq, int start, int end);
void mergeSortDeque(std::deque<int> &deq, int start, int mid, int end);

#endif