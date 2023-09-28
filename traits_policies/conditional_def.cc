/* https://blog.csdn.net/iaibeyond/article/details/119895400 */
/**
 * The typename keyword must be used if a name in a template definition is a qualified name that is
 * dependent on a template argument; it's optional if the qualified name isn't dependent.
 */

/**
 * trait is a special class to characterize the type features like is_void, is_pointer and as
 * such.
 * std::numeric_limits is a type trait from the C++ standard library which defines the maximum
 * value for different built-in types.
 */

/* Primary Template. */
template<bool _Test, class _Ty1, class _Ty2>
struct conditional
{
    /* alias */
    using type = _Ty2;
};

/* partial specialization */
template<class _Ty1, class _Ty2>
struct conditional<true, _Ty1, _Ty2>
{
    /* alias */
    using type = _Ty1;
};

/* https://en.cppreference.com/w/cpp/language/type_alias */
/* alias template */
/* Here, the keyword typename is necessary because the name type is dependent on template args. */
template<bool _Test, class _Ty1, class _Ty2>
using condtional_t = typename conditional<_Test, _Ty1, _Ty2>::type;

/*https://blog.csdn.net/iaibeyond/article/details/119895400 */

int
main(int argc, char** argv)
{
    return 0;
}
