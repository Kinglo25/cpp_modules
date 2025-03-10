#include "PmergeMe.hpp"

typedef unsigned long long timestamp_t;

static timestamp_t get_timestamp ()
{
	struct timeval now;
	gettimeofday (&now, NULL);
	return  now.tv_usec + (timestamp_t)now.tv_sec * 1000000;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: ./PmergeMe \"<expression>\"" << std::endl;
        return 1;
    }
    std::vector<int> vec; // vecst of integers
    std::deque<int> deq; // deque of integers
    
    readInput(vec, deq, argc, argv);
    std::cout << "before: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    timestamp_t start = get_timestamp();
    mergeInsertionSortVector(vec, 0, vec.size());
    timestamp_t end = get_timestamp();
    double vecTime = double(end - start) / CLOCKS_PER_SEC * 1000;

    start = get_timestamp();
    mergeInsertionSortDeque(deq, 0, deq.size());
    end = get_timestamp();
    double deqTime = double(end - start) / CLOCKS_PER_SEC * 100;

    std::cout << "after: ";
    for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: "
              << std::fixed << std::setprecision(5) << vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: "
              << std::fixed << std::setprecision(5) << deqTime << " us" << std::endl;
}