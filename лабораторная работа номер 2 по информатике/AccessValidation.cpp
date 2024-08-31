#include <iostream>
#include "AccessValidation.h"
#include <string>

void validateAccessByIndex(size_t index, const char* function, size_t size)
{
    validateListNotEmpty(function, size);
    validateIndex(index, function, size);
}

void validateListNotEmpty(const char* function, size_t size)
{
    std::string failedFunctionName = function;
    if (size == 0)
    {
        throw std::logic_error(failedFunctionName + " function failed \nError: ReadingEmptyList");
    }
}

void validateIndex(size_t index, const char* function, size_t size)
{
    std::string failedFunctionName = function;
    if (index >= size)
    {
        throw std::out_of_range(failedFunctionName + " function failed \nError: IndexOutOfRange");
    }
}