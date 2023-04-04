#include <fstream>
#include <cmath>

// http://personalpages.to.infn.it/~mignone/Numerical_Algorithms/gnuplot.pdf
int
main()
{
    std::ofstream datafile;
    datafile.open("data.txt", std::ios_base::trunc);

    float start = 0.0;
    float diff = 0.1;
    int sample_cnt = 200;

    for (int i = 0; i < sample_cnt; ++i)
    {
        float x = start + i * diff;
        datafile << x << " " <<  x * x << " " <<  std::sin(x) << std::endl;
    }

    datafile.close();

    return 0;
}
