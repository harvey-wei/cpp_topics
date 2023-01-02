#include <iostream>

template <typename T>
struct remove_bounds
{ typedef T type; };

template <typename T, std::size_t N>
struct remove_bounds<T[N]>
{ typedef T type; };


/* is_void is a trait class */
/* Primary template */
template< typename T >
struct is_void
{
  static const bool value = false;
};

/* A specialization for void*/
template<>
struct is_void<void>{
  static const bool value = true;
};

int main()
{
    return 0;
}


/**
 * Q: What is traits and polices?
 * A: A policy is a class or class template that defines an interface as a service to other classes.
 * Traits define type interfaces, and policies define function interfaces, so they are closely
 * related. Sometimes, a single class template implements traits and policies.
 * Ref: https://www.oreilly.com/library/view/c-in-a/059600298X/ch08s04.html
 * Think of a trait as a small object whose main purpose is to carry information used by another
 * object or algorithm to determine "policy" or "implementation details". - Bjarne Stroustrup
 * By convention, traits are always implemented as structs. Another convention is that the structs
 * used to implement traits are knows as trait classes which are used to carry information about
 * type.
 * std::numeric_limits class is a typical example of trait class which is often implemented via
 * (partial) template specialization.
 * https://www.bogotobogo.com/cplusplus/template_specialization_traits.php
 * https://accu.org/journals/overload/9/43/frogley_442/
 *
 * A policy is a generic (template) function or class whose behavior can be configured.
 * https://www.modernescpp.com/index.php/policy-and-traits
 * The template parameter in std::vector and std::unordered_map can be thought of as policy!
 *
 * https://blog.andreiavram.ro/cpp-policy-based-design/
 */
