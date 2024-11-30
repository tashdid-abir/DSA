#include <bits/stdc++.h>

int main() {

    std::vector<std::pair<int,int>> activities = {
        {12,25},{20,30},{10,20}
    };

    std::sort( activities.begin(), activities.end(), [](const std::pair<int,int>& a, const std::pair<int,int>& b) {
        return a.second < b.second;
    } );

    int count = 1;
    int last_finish = activities[0].second;

    for(int i = 1; i < activities.size(); i++) {
        if(activities[i].first >= last_finish) {
            count++;
            last_finish = activities[i].second;
        } 
    }

    std::cout << count;

    return 0;
}