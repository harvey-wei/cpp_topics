#include <iostream>
#include <iterator>
#include <random>
#include <vector>

/* https://leimao.github.io/blog/CPP-Traits/ */

template <typename T>
class UniformDist
{
public:
    UniformDist(T a, T b) :
        m_min{a}, m_max{b}, m_uniform_dist{a, b} // call the constuctor of T and dist_t
    {}
    T operator()(std::mt19937& random_engine)
    {
        return m_uniform_dist(random_engine);
    }

private:
    T const m_min;
    T const m_max;
    using dist_t = std::conditional_t<std::is_integral<T>::value,
                                      std::uniform_int_distribution<T>,
                                      std::uniform_real_distribution<T>>;
    dist_t m_uniform_dist;
};

template <typename T>
std::vector<T> create_random_vector(size_t n, T a, T b,
                                    std::mt19937& random_engine)
{
    UniformDist<T> uniform_dist{a, b};
    std::vector<T> vec(n, 0.0);
    for (size_t i{0}; i < n; ++i)
    {
        vec[i] = uniform_dist(random_engine);
    }
    return vec;
}

int main()
{
    size_t const n{8};
    unsigned int const seed{0U};
    std::mt19937 random_engine{seed};
    std::vector<double> const random_vector_double{
        create_random_vector(n, -16.0, 16.0, random_engine)};
    std::cout << "Random Vector of Doubles: " << std::endl;
    std::copy(random_vector_double.begin(), random_vector_double.end(),
              std::ostream_iterator<double>(std::cout, " "));
    std::cout << std::endl;
    std::vector<int> const random_vector_int{
        create_random_vector(n, -16, 16, random_engine)};
    std::cout << "Random Vector of Integers: " << std::endl;
    std::copy(random_vector_int.begin(), random_vector_int.end(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}
