/************************************************************************
 * Implementation of standard library functions for practice in for
 * the assignment "The-STL" in CIS 263.
 *
 * @author David Whitters
 * @date 5/14/17
 ************************************************************************/

#include "stl_functions.h"
#include <algorithm>

/**
 * Copies a passed in vector and returns the copy. The STL function
 * std::copy is used to accomplish this.
 *
 * @param oldVector A reference to a vector that will be copied.
 *
 * @return vector<int> A vector that is a copy of the vector whose
 *                     reference was received as a parameter.
 */
std::vector<int> copyVec(const std::vector<int> & oldVector)
{
    /*
        Declares and initializes a vector with the same size as
        the parameter vector.
    */
    std::vector<int> new_vec(oldVector.size());

    std::copy(oldVector.begin(), oldVector.end(), new_vec.begin());

    return new_vec;
}

/**
 * Sorts the vector referenced by the parameter reference that is
 * received using the STL function std::sort.
 *
 * @param oldVector A reference to a vector that will be sorted.
 */
void sortVec(std::vector<int> & oldVector)
{
    // Sorts using the default operator <.
    std::sort(oldVector.begin(), oldVector.end());
}

/**
 * Doubles all elements in the vector referenced by the parameter
 * reference that is received using the STL function std::for_each.
 *
 * @param oldVector Reference to a vector whose elements will all be
 *                  doubled.
 */
void doubleVec(std::vector<int> & oldVector)
{
    // Loop through all vector elements and double them using a lambda.
    std::for_each(oldVector.begin(),
                  oldVector.end(),
                  [](int& n){n *= 2;});
}

/**
 * Determines whether an element in the referenced vector matches the
 * item parameter using the STL function std::find.
 *
 * @param ourVector Referenced vector to search.
 * @param item std::string to search for in the referenced vector.
 *
 * @return bool True when the referenced vector contains the item,
 *              otherwise false.
 */
bool containsItem(std::vector<std::string> & ourVector,
                  std::string item)
{
    auto result = std::find(ourVector.begin(), ourVector.end(), item);
    return (result != ourVector.end());
}

/**
 * Returns a vector that contains only the elements that
 * are in both of the input parameter vectors using the STL function
 * std::set_intersection.
 *
 * @param a One of the two vectors analyzed to find matching elements.
 * @param b One of the two vectors analyzed to find matching elements.
 *
 * @return std::vector<int> The vector containing only the elements
 *                          that are contained in both of the parameter
 *                          vectors.
 */
std::vector<int> inBoth(std::vector<int> a, std::vector<int> b)
{
    std::vector<int> return_vec;

    // The vectors must be sorted according to the standard library.
    sortVec(a);
    sortVec(b);

    /*
        Find all matching elements in the vectors and insert them into
        return_vec.
    */
    std::set_intersection(a.begin(), a.end(),
                          b.begin(), b.end(),
                          std::back_inserter(return_vec));

    return return_vec;
}
