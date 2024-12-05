#include <bits/stdc++.h>

int main() {

    std::vector<std::pair<float,float>> schedules = { 
        {2.00, 2.30},{2.10,3.40},{3.00,3.20},{3.20,4.30},{3.50,4.00},{5.00,5.20} 
    };

    std::sort(schedules.begin(), schedules.end(), [](const std::pair<float,float>& a, const std::pair<float,float>& b ) {
        return a.second < b.second;
    });

    int count = 1;
    float last_departure = schedules[0].second;

    for(int i = 1; i < schedules.size(); i++) {
        if(schedules[i].first <= last_departure) count++;
            
        else last_departure = schedules[i].second;
    }

    std::cout << count;

    return 0;
}