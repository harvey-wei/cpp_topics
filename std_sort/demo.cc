#include<iostream>
#include<algorithm>  // for std::sort()
#include<vector>
using namespace std;

void print_vec(const std::vector<int> &vecs)
{
    for (const auto &vec: vecs)
    {
        cout << " " << vec;
    }

    cout << endl;
}

bool my_func(const int &lhs, const int &rhs)
{
    return lhs > rhs;
}

struct my_class
{
    bool operator()(const int &lhs, const int &rhs)
    {
        return lhs > rhs;
    }
};

int main()
{
    //array initialization
    int demo[5] = {5, 4, 3, 3, 1};

    int len = sizeof(demo)/sizeof(demo[0]); //sizeof return the size in bytes

    cout << "Before sorting array : ";
    for(int i=0; i<len; i++)
    {
        cout<<" "<<demo[i];
    }

    /* By default, std::sort() sort the data in non-descending order in-place. */
    std::sort(demo, demo + len); //Sorting demo array in-place

    cout << "\n\nAfter sorting array : ";
    for(int i=0; i<len; i++)
    {
        cout<<" "<<demo[i];
    }
    cout << endl << endl;

    /* Sorting in non-ascending order in place. */
    int myints[] = {32,71,12,45,26,80,53,33};
    std::vector<int> myvector(myints, myints+8);               // 32 71 12 45 26 80 53 33
    cout<<"Before sorting array : ";
    print_vec(myvector);

    /* std::sort(myvector.begin(), myvector.end(), greater<int>()); */
    /* Lambda function */
    std::sort(myvector.begin(), myvector.end(),
            [](const int &lhs, const int &rhs){ return lhs > rhs;});
    /* std::sort(myvector.begin(), myvector.end(), my_func); */
    my_class my_functor;
    /* std::sort(myvector.begin(), myvector.end(), my_functor); */
    cout<<"\n\nAfter sorting array : ";
    print_vec(myvector);


    string s = "edcba";
    std::sort(s.begin(), s.end());

    return 0;
}

/*
    ref: https://www.digitalocean.com/community/tutorials/sort-in-c-plus-plus
    ref: https://cplusplus.com/reference/algorithm/sort/
    void sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp);
    Q: What algorithm does the std::sort() use?
    A: It is a combination of Quick Sort, Heap Sort, and Insertion Sort.

    Q: Is std::sort() in-place?
    A: Yes. Here, the function does not return anything. It just updates the elements/items from
      the first up to but excluding the last iterables or positions

    Q: What is the default order?
    A: When not specified, the sorting takes place in ascending order considering it to be the
      std::less<int>() function by default. If lhs < rhs then lhs is placed before rhs. (lhs, rhs)
      If the compare_func returns true, the first item is placed before the second item.

    Q:
*/
