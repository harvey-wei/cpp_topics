#include <iostream>
#include <limits>

template<typename T>
class Allocator
{
public :
    //    typedefs
    using value_type = T;
    /* typedef T value_type; */
    typedef value_type* pointer;
    typedef const value_type* const_pointer;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef std::size_t size_type;
    typedef std::ptrdiff_t difference_type;

public :
    //    convert an allocator<T> to allocator<U>
    template<typename U>
    struct rebind
    {
        typedef Allocator<U> other;
    };

public :
    inline explicit Allocator() {}
    inline ~Allocator() {}
    inline explicit Allocator(Allocator const&) {}
    template<typename U>
    inline explicit Allocator(Allocator<U> const&) {}

    //    address
    inline pointer address(reference r) { return &r; }
    inline const_pointer address(const_reference r) { return &r; }

    //    memory allocation
    // :: w/o means global namespace
    // operator new allocates memory from heap
    inline pointer allocate(size_type cnt,
       typename std::allocator<void>::const_pointer = 0) {
      return reinterpret_cast<pointer>(::operator new(cnt * sizeof (T)));
    }
    inline void deallocate(pointer p, size_type) {
        ::operator delete(p);
    }

    //    size
    inline size_type max_size() const {
        return std::numeric_limits<size_type>::max() / sizeof(T);
 }

    //    construction/destruction
    inline void construct(pointer p, const T& t) { new(p) T(t); }
    inline void destroy(pointer p) { p->~T(); }

    inline bool operator==(Allocator const&) { return true; }
    inline bool operator!=(Allocator const& a) { return !operator==(a); }
};    //    end of class Allocator

int main()
{
    return 0;
}


/**
 * new vs operator new
 * Ref: https://www.geeksforgeeks.org/new-vs-operator-new-in-cpp/
 * The best tutorial: https://www.codeproject.com/Articles/4795/C-Standard-Allocator-An-Introduction-and-Implement
 * Good tutorial: https://docs.ros.org/en/foxy/Tutorials/Advanced/Allocator-Template-Tutorial.html
 */
