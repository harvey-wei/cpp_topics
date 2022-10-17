#include <iostream>
#include <cmath> /* for atan2 */
#include <vector>
#include <utility>  /* std::pair, std::make_pair */
#include <stack>

float deg_to_rad(const float & deg)
{
    return M_PI * deg / 180.0f;
}

float rad_to_deg(const float & rad)
{
    return 180.0f * rad / M_PI;
}

void deg_rad_convert_test()
{
    float rad, deg;
    int test_cases_cnt;
    std::cout << "The number of test cases: ";
    std::cin >> test_cases_cnt;
    std::cout << std::endl;

    // for deg2rad
    std::cout << "Please input the angles in degree!" << std::endl;
    for (int i = 0; i < test_cases_cnt; ++i)
    {
        std::cin >> deg;
        std::cout << "The angle in radian is " << deg_to_rad(deg);
    }

    std::cout << std::endl;

    std::cout << "Please enter the angles in radian!" << std::endl;
    for (int i = 0; i < test_cases_cnt; ++i)
    {
        std::cin >> rad;
        std::cout << "The angle in degree is " << rad_to_deg(rad);
    }

    std::cout << std::endl;

}

#define DEBUG 0

bool
get_arc_angle_by_dfs(std::vector<float> &angle_set_rad, const float &angle_res_rad,
        const float &max_arc_gap_rad, float &central_angle, float &coverage, float &real_max_gap_rad)
{
    if (angle_set_rad.empty()) return false;

    const float angle_rad_tol = 1e-4;
    for (auto &angle: angle_set_rad)
    {
        if ((angle < -M_PI && std::abs(angle + M_PI) > angle_rad_tol) ||
                (angle > M_PI && std::abs(angle - M_PI) > angle_rad_tol))
        {
#if DEBUG
            std::cout <<  angle << " is out of range!" << std::endl;
#endif
            return false;
        }

        angle = std::max<float>(-M_PI, angle);
        angle = std::min<float>(M_PI, angle);
    }

    int max_arc_gap = max_arc_gap_rad / angle_res_rad;
    int sector_cnt = 2 * M_PI / angle_res_rad + 1;
    std::vector<bool> is_sector_in_angle(sector_cnt, false);

#if DEBUG
    std::cout << "max_arc_gap " << max_arc_gap << std::endl;
    std::cout << "sector_cnt " << sector_cnt << std::endl;
#endif

    int min_idx = INT32_MAX;
    int occupied_sec = 0;
    for (const auto &angle: angle_set_rad)
    {
        int idx = (angle + M_PI) / angle_res_rad + 0.5;
#if DEBUG
        std::cout << "The sector index: " << idx << std::endl;
#endif
        if (true == is_sector_in_angle[idx]) continue;
        ++occupied_sec;
        min_idx = std::min(min_idx, idx);
        is_sector_in_angle[idx] = true;
    }

#if DEBUG
    std::cout << "Occupied sector count " << occupied_sec << std::endl;
    std::cout << "The min index is " << min_idx << std::endl;
#endif

    int covered_sec_cnt = 0;
    std::vector<bool> is_sector_visited(sector_cnt, false);
    int global_max_arc_gap = 0;

    for (unsigned int idx = 0u; idx < is_sector_in_angle.size(); ++idx)
    {
        if (false == is_sector_in_angle[idx] || true == is_sector_visited[idx]) continue;

        std::stack<int> sector_idx_stack;
        sector_idx_stack.push(idx);
        is_sector_visited[idx] = true;
        ++covered_sec_cnt;

        while(!sector_idx_stack.empty())
        {
            int top_sec_idx = sector_idx_stack.top();
            sector_idx_stack.pop();
            std::vector<int> dirs = {-1, 1};
            for (const auto & dir: dirs)
            {
                int arc_gap = 0;
                int curr_sec_idx = top_sec_idx;

#if DEBUG
                std::cout << "top_sec_idx" << top_sec_idx << std::endl;
#endif
                /* search for the neighbor in one direction. */
                while (true)
                {
                    curr_sec_idx = (curr_sec_idx + dir + sector_cnt) % sector_cnt;
#if DEBUG
                    std::cout << "The dir " << dir << std::endl;
                    std::cout << "curr_sec_idx " << curr_sec_idx <<std::endl;
#endif

                    if (arc_gap > max_arc_gap || (true ==  is_sector_visited[curr_sec_idx]))
                    {
                        break;
                    }

                    /* arc_gap <= max_arc_gap */
                    if (true == is_sector_in_angle[curr_sec_idx])
                    {
#if DEBUG
                        std::cout << curr_sec_idx << "is found!" << std::endl;
#endif
                        /* The neighbor is found! */
                        sector_idx_stack.push(curr_sec_idx);
                        /* We only keep track of occupied sectors. */
                        is_sector_visited[curr_sec_idx] = true;
                        covered_sec_cnt += 1 + arc_gap;
                        global_max_arc_gap = std::max(arc_gap, global_max_arc_gap);
                        break;
                    }
                    else
                    {
                        /* Meet one gap. */
                        ++arc_gap;
                    }
                }
            }
        }
    }

    if (covered_sec_cnt <= 1)
    {
        central_angle = 0.0f;
        return false;
    }

    central_angle = covered_sec_cnt * angle_res_rad;
    coverage = float(occupied_sec) / float(covered_sec_cnt);
    real_max_gap_rad = global_max_arc_gap * angle_res_rad;

#if DEBUG
    std::cout << "covered_sec_cnt " << covered_sec_cnt << std::endl;
    std::cout << "global_max_arc_gap " << global_max_arc_gap << std::endl;
#endif

    return true;
}

int main()
{
    // 42 deg
    /* std::vector<float> angle_set_rad = */
    /*         {deg_to_rad(170.0f), deg_to_rad(172.0f), deg_to_rad(175.0f), deg_to_rad(178.0f), */
    /*          deg_to_rad(179.0f), deg_to_rad(-178.0f), deg_to_rad(-174.0f), deg_to_rad(-170.0f), */
    /*          deg_to_rad(-167.0f), deg_to_rad(-163.0f), deg_to_rad(-160.0f), deg_to_rad(-150.0f)}; */
    // 47 deg
    /* std::vector<float> angle_set_rad = */
    /*         {deg_to_rad(165.0f), deg_to_rad(172.0f), deg_to_rad(175.0f), deg_to_rad(178.0f), */
    /*          deg_to_rad(179.0f), deg_to_rad(-178.0f), deg_to_rad(-174.0f), deg_to_rad(-170.0f), */
    /*          deg_to_rad(-167.0f), deg_to_rad(-163.0f), deg_to_rad(-160.0f), deg_to_rad(-150.0f)}; */

    // 15 deg
    /* std::vector<float> angle_set_rad = */
    /*         {deg_to_rad(0.0f), deg_to_rad(5.0f), deg_to_rad(10.0f), deg_to_rad(15.0f)}; */

    // 135 deg
    /* std::vector<float> angle_set_rad = */
    /*         {deg_to_rad(0.0f), deg_to_rad(5.0f), deg_to_rad(10.0f), deg_to_rad(15.0f), */
    /*             deg_to_rad(20.0f), deg_to_rad(27.0f), deg_to_rad(35.0f), deg_to_rad(40.0f), */
    /*             deg_to_rad(45.0f), deg_to_rad(50.0f), deg_to_rad(55.0f), deg_to_rad(60.0f), */
    /*             deg_to_rad(65.0f), deg_to_rad(70.0f), deg_to_rad(75.0f), deg_to_rad(80.0f), */
    /*             deg_to_rad(85.0f), deg_to_rad(87.0f), deg_to_rad(90.0f), deg_to_rad(95.0f), */
    /*             deg_to_rad(100.0f), deg_to_rad(105.0f), deg_to_rad(110.0f), deg_to_rad(115.0f), */
    /*             deg_to_rad(120.0f), deg_to_rad(125.0f), deg_to_rad(130.0f), deg_to_rad(135.0f), */
    /*         }; */
    // 135 but negative
    std::vector<float> angle_set_rad =
            {deg_to_rad(0.0f), deg_to_rad(-5.0f), deg_to_rad(-10.0f), deg_to_rad(-15.0f),
                deg_to_rad(-20.0f), deg_to_rad(-27.0f), deg_to_rad(-35.0f), deg_to_rad(-40.0f),
                deg_to_rad(-45.0f), deg_to_rad(-50.0f), deg_to_rad(-55.0f), deg_to_rad(-60.0f),
                deg_to_rad(-65.0f), deg_to_rad(-70.0f), deg_to_rad(-75.0f), deg_to_rad(-80.0f),
                deg_to_rad(-85.0f), deg_to_rad(-87.0f), deg_to_rad(-90.0f), deg_to_rad(-95.0f),
                deg_to_rad(-100.0f), deg_to_rad(-105.0f), deg_to_rad(-110.0f), deg_to_rad(-115.0f),
                deg_to_rad(-120.0f), deg_to_rad(-125.0f), deg_to_rad(-130.0f), deg_to_rad(-135.0f),
            };

    // 25 deg
    /* std::vector<float> angle_set_rad = {deg_to_rad(-10.0f), deg_to_rad(-8.0f), deg_to_rad(-5.0f), */
    /*         deg_to_rad(0.0f), deg_to_rad(4.0f), deg_to_rad(8.0f), deg_to_rad(15.0f), */
    /*         }; */

    // Big gap should lead to return the sum of two separate arc angles!
    /* std::vector<float> angle_set_rad = {deg_to_rad(-20.0f), deg_to_rad(-15.0f), deg_to_rad(-10.0f), */
    /*     deg_to_rad(2.0f), deg_to_rad(4.0f), deg_to_rad(8.0f), deg_to_rad(15.0f)}; */

    // Empty angle_res_rad
    /* std::vector<float> angle_set_rad = {}; */

    // 215 deg
    /* std::vector<float> angle_set_rad = */
    /*         {deg_to_rad(0.0f), deg_to_rad(5.0f), deg_to_rad(10.0f), deg_to_rad(15.0f), */
    /*             deg_to_rad(20.0f), deg_to_rad(27.0f), deg_to_rad(35.0f), deg_to_rad(40.0f), */
    /*             deg_to_rad(45.0f), deg_to_rad(50.0f), deg_to_rad(55.0f), deg_to_rad(60.0f), */
    /*             deg_to_rad(65.0f), deg_to_rad(70.0f), deg_to_rad(75.0f), deg_to_rad(80.0f), */
    /*             deg_to_rad(85.0f), deg_to_rad(87.0f), deg_to_rad(90.0f), deg_to_rad(95.0f), */
    /*             deg_to_rad(100.0f), deg_to_rad(105.0f), deg_to_rad(110.0f), deg_to_rad(115.0f), */
    /*             deg_to_rad(120.0f), deg_to_rad(125.0f), deg_to_rad(130.0f), deg_to_rad(135.0f), */
    /*             deg_to_rad(140.0f), deg_to_rad(145.0f), deg_to_rad(150.0f), deg_to_rad(155.0f), */
    /*             deg_to_rad(160.0f), deg_to_rad(165.0f), deg_to_rad(170.0f), deg_to_rad(175.0f), */
    /*             deg_to_rad(178.0f), deg_to_rad(-175.0f), deg_to_rad(-170.0f), deg_to_rad(-165.0f), */
    /*             deg_to_rad(-160.0f), deg_to_rad(-155.0f), deg_to_rad(-150.0f), deg_to_rad(-145.0f), */
    /*         }; */

    float angle_res_rad = deg_to_rad(1.0f);
    float max_arc_gap_rad = deg_to_rad(10.0f);
    float central_angle = 0.0f;
    float angle_coverage = 0.0f;
    float real_max_gap_rad = 0.0f;
    bool ret = get_arc_angle_by_dfs(angle_set_rad, angle_res_rad, max_arc_gap_rad, central_angle,
            angle_coverage, real_max_gap_rad);

    std::cout << "Succeed in computing the angle? " << (true == ret ? "Yes" : "No") << std::endl;
    std::cout << "The central angle is " << rad_to_deg(central_angle) << std::endl;
    std::cout << "The angle coverage is " <<  angle_coverage << std::endl;
    std::cout << "The real_max_gap_deg " << rad_to_deg(real_max_gap_rad) << std::endl;

    return 0;
}
