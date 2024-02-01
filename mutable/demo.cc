#include <iostream>
#include <cstring>

class CTextBlock
{
public:
    const char& operator[](std::size_t position) const
    {
        // index is a unsigned int
        return pText[position];
    }

    // const qualifies the first implicit parameter this pointer.
    // Hence, const qualifing member function can also be overloaded.
    char& operator[](std::size_t position)
    {
        return pText[position];
    }

    std::size_t length() const; // a const member function means const this pointer

private:
    char* pText;
    mutable std::size_t textLength; // mutable means can be modified in a const member function
    mutable bool lengthIsValid;
};

std::size_t CTextBlock::length() const
{
    if (!lengthIsValid) {
        textLength = std::strlen(pText); // strlen is not a const member function
        lengthIsValid = true;
    }

    return textLength;
}

int
main(int argc, char** argv)
{
    return 0;
}
