class Solution
{
public:
    //Time:O(N) | O(1)
    int nextGreaterElement(int n)
    {

        //For doing array manipulation
        string str = to_string(n);

        int deflectionPoint = str.size() - 1;

        // Left number is smaller than Right Number
        while (deflectionPoint > 0)
        {
            if (str[deflectionPoint] > str[deflectionPoint - 1])
            {
                break;
            }
            deflectionPoint--;
        }
        if (deflectionPoint == 0)
            return -1;

        int firstIndex = deflectionPoint - 1;
        int secondIndex = str.size() - 1;
        while (firstIndex < secondIndex)
        {
            if (str[secondIndex] > str[firstIndex])
            {
                break;
            }
            secondIndex--;
        }

        int indexToSwap = secondIndex;
        //str[deflectionPoint-1]<str[indexToSwap]
        //Swap the values
        char temp = str[deflectionPoint - 1];
        str[deflectionPoint - 1] = str[indexToSwap];
        str[indexToSwap] = temp;

        //Reverse the string after deflection
        int first = deflectionPoint;
        int second = str.size() - 1;

        while (first < second)
        {
            char temp = str[first];
            str[first] = str[second];
            str[second] = temp;
            second--;
            first++;
        }

        float ans = stof(str);
        if (ans < INT_MAX)
        {
            return stoi(str);
        }
        return -1;
    }
};