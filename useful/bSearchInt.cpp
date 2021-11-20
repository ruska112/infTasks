#include <iostream>
#include <vector>
#include <cmath>

int bSearch(std::vector<int> numbers, int value, int low, int high)
{
    int mid = (low + high) / 2;

    if (value < numbers[mid])
    {
        return bSearch(numbers, value, low, mid - 1);
    }
    else if (value > numbers[mid])
    {

        return bSearch(numbers, value, mid + 1, high);
    }
    else
    {
        return mid;
    }
}

int main()
{
    std::vector<int> nums;

    nums = {0, 1, 2, 3, 4, 5, 6};

    int index = bSearch(nums, 2, 0, 7);

    printf("index = %d\n", index);

    return 0;
}
