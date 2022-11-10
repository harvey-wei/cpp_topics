#include <iostream>
#include <cstdlib>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
using namespace std;

/*
   ref: https://zhuanlan.zhihu.com/p/427271798
*/
int main ()
{
    pcl::PointCloud<pcl::PointXYZ> cloud;

    // Fill in the cloud data
    cloud.width    = 200;
    cloud.height   = 100;
    cloud.is_dense = false;
    cloud.resize (cloud.width * cloud.height);

    for (auto& point: cloud)
    {
        point.x = 1024 * rand () / (RAND_MAX + 1.0f);
        point.y = 1024 * rand () / (RAND_MAX + 1.0f);
        point.z = 1024 * rand () / (RAND_MAX + 1.0f);
    }

    pcl::io::savePCDFileASCII ("test_pcd.pcd", cloud);
    std::cerr << "Saved " << cloud.size () << " data points to test_pcd.pcd." << std::endl;

    for (const auto& point: cloud)
        std::cerr << "    " << point.x << " " << point.y << " " << point.z << std::endl;

    return (0);
}
