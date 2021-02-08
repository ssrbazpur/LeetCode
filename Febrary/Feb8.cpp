//https: //www.geeksforgeeks.org/copy-constructor-in-cpp/
//https://www.learncpp.com/cpp-tutorial/constructors-and-initialization-of-derived-classes/

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *		Iterator(const vector<int>& nums);
        //Copy Constructor
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator
{
    int peekValue = -1;
    bool hasNextValue;

public:
    // : means Iterator class has been initialised at the same time.
    PeekingIterator(const vector<int> &nums) : Iterator(nums)
    {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.

        hasNextValue = Iterator::hasNext();
        if (hasNextValue)
        {
            peekValue = Iterator::next();
        }
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek()
    {
        return peekValue;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next()
    {
        int currVal = peekValue;
        hasNextValue = Iterator::hasNext();
        if (hasNextValue)
        {
            peekValue = Iterator::next();
        }

        return currVal;
    }

    bool hasNext() const
    {
        return hasNextValue;
    }
};