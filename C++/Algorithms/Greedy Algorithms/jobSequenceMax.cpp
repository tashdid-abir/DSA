#include <bits/stdc++.h>

struct jobs {
    std::string ID;
    int profit, deadline;
};

int main() {

    int N, maxDeadline = 0, maxProfit = 0;

    std::cout << "\nEnter number of jobs : ";
    std::cin >> N;
    std::vector<jobs> schedules(N);

    for(int i = 0; i < schedules.size(); i++) {

        std::cout << "\n\nEnter job " << i+1 << " ID (A,B,C...) : ";
        std::cin >> schedules[i].ID;

        std::cout << "Enter " << i+1 << " profit : ";
        std::cin >> schedules[i].profit;

        std::cout << "Enter " << i+1 << " deadline : ";
        std::cin >> schedules[i].deadline;

        if(schedules[i].deadline > maxDeadline) maxDeadline = schedules[i].deadline;
    }

    sort(schedules.begin(), schedules.end(), [](const jobs& a, const jobs& b) {
        return a.profit > b.profit;
    });

    std::vector<int> timeSlot(maxDeadline, 0);

    std::cout << "\n\nMaximum jobs list : ";

    for(int i = 0; i < schedules.size(); i++) {
        for(int j = schedules[i].deadline - 1; j >= 0; j--) {
            if(timeSlot[j] == 0) {
                timeSlot[j] = 1;
                maxProfit += schedules[i].profit;
                std::cout << schedules[i].ID << " ";
                break;
            }
        }
    }

    std::cout << "\nMaximum profit : " << maxProfit;
    std::cout << "\n\n";

    return 0;
}