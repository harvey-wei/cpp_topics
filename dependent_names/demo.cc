#include <iostream>

template <typename T>
struct wrapper
{
   using value_type = T; // alias

   value_type value;
};

template<typename T, typename U>
struct dual_wrapper
{
    using value_type1 = T;
    using value_type2 = U;

    value_type1 value;
    value_type2 another_value;
};

/**
 * if you want to restrict the instantiation to wrappers that have a single type parameter.
 * using template template paramter template <typename> class T where keyword class is required.
 */
/* template <typename T> */
template<typename V, template<typename> class T>
struct foo
{
   T<V> wrapped_value;

   /**
    * value_type is a name dependent on a template paramter T
    *
    * typename T::value_type get_wrapped_value() { return wrapped_value.value; }
    * This is where you must use typename but class is not allowed.
    */
   // T::value_type get_wrapped_value() /* Error: missing typename prior to the dependent type name. */
   /* typename T::value_type get_wrapped_value() */
   /* { */
   /*     return wrapped_value.value; */
   /* } */

   using wrapped_value_type = typename T<V>::value_type;

   wrapped_value_type get_wrapped_value()
   {
       return wrapped_value.value;
   }
};

int main()
{
   /* foo<wrapper<int>> f{ {42} }; */
   foo<int, wrapper> f{{42}};
   std::cout << f.get_wrapped_value() << '\n';
}

/**
 * https://www.geeksforgeeks.org/uniform-initialization-in-c/
 */
