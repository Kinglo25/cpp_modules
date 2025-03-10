#include "PmergeMe.hpp"

bool isValid(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
        {
            std::cerr << "Error: Invalid input => " << str << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    if (atoi(str) < 0)
    {
        std::cerr << "Error: Invalid input => " << str << std::endl;
        exit(EXIT_FAILURE);
    }
    return true;
}

void readInput(std::vector<int> &vec, std::deque<int> &deq, int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        if (isValid(argv[i]))
        {
            deq.push_back(atoi(argv[i]));
            vec.push_back(atoi(argv[i]));
        }
    }
}

void mergeInsertionSortVector(std::vector<int> &vec, int start, int end)
{
    if (start < end)
    {
        if (end - start < 10)
            insertionSortVector(vec, start, end);   
        else
        {
            int mid = start + (end - start) / 2;
            mergeInsertionSortVector(vec, start, mid);
            mergeInsertionSortVector(vec, mid, end);
            mergeSortVector(vec, start, mid, end);
        }
    }
}

void insertionSortVector(std::vector<int> &vec, int start, int end)
{
    for (int i = start + 1; i <= end; i++)
    {
        int key = vec[i];
        int j = i - 1;
        while (j >= start && vec[j] > key)
        {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}

void mergeSortVector(std::vector<int> &vec, int start, int mid, int end)
{
    std::vector<int> left(vec.begin() + start, vec.begin() + mid);
    std::vector<int> right(vec.begin() + mid, vec.begin() + end);
    size_t i = 0;
    size_t j = 0;
    int k = start;
    
    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[j])
            vec[k++] = left[i++];
        else
            vec[k++] = right[j++];
    }
    
    while (i < left.size())
        vec[k++] = left[i++];
    while (j < right.size())
        vec[k++] = right[j++];
}

void mergeInsertionSortDeque(std::deque<int> &deq, int start, int end)
{
    if (start < end)
    {
        if (end - start < 10)
            insertionSortDeque(deq, start, end);
        else
        {
            int mid = start + (end - start) / 2;
            mergeInsertionSortDeque(deq, start, mid);
            mergeInsertionSortDeque(deq, mid, end);
            mergeSortDeque(deq, start, mid, end);
        }
    }
}

void insertionSortDeque(std::deque<int> &deq, int start, int end)
{
    for (int i = start + 1; i < end; i++)
    {
        int key = deq[i];
        int j = i - 1;
        while (j >= start && deq[j] > key)
        {
            deq[j + 1] = deq[j];
            j--;
        }
        deq[j + 1] = key;
    }
}

void mergeSortDeque(std::deque<int> &deq, int start, int mid, int end)
{
    std::deque<int> left(deq.begin() + start, deq.begin() + mid);
    std::deque<int> right(deq.begin() + mid, deq.begin() + end);
    size_t i = 0;
    size_t j = 0;
    int k = start;
    
    while (i < left.size() && j < right.size())
    {
        if (left[i] <= right[j])
            deq[k++] = left[i++];
        else
            deq[k++] = right[j++];
    }
    
    while (i < left.size())
        deq[k++] = left[i++];
    while (j < right.size())
        deq[k++] = right[j++];
}
