#include <bits/stdc++.h>
using namespace std;

struct Job {
    string ID;
    int timeRequired;
    int lossPerDay;
};

int main() {
    int N;

    cout << "\nEnter number of jobs: ";
    cin >> N;
    
    vector<Job> jobs(N);

    for(int i = 0; i < N; i++) {
        cout << "\nEnter job " << i+1 << " ID (A, B, C, ...): ";
        cin >> jobs[i].ID;
        cout << "Enter job " << i+1 << " time required: ";
        cin >> jobs[i].timeRequired;
        cout << "Enter job " << i+1 << " loss per day: ";
        cin >> jobs[i].lossPerDay;
    }

    sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
        if (a.lossPerDay == b.lossPerDay)
            return a.timeRequired > b.timeRequired;
        return a.lossPerDay > b.lossPerDay;
    });

    int maxTime = 0;
    for (const auto& job : jobs) {
        maxTime = max(maxTime, job.timeRequired);
    }

    vector<bool> timeSlot(maxTime, false);  
    vector<string> scheduledJobs;           
    int totalLoss = 0;              

    for (int i = 0; i < N; i++) {
        for (int j = jobs[i].timeRequired - 1; j >= 0; j--) {
            if (!timeSlot[j]) {
                timeSlot[j] = true;
                scheduledJobs.push_back(jobs[i].ID);
                totalLoss += jobs[i].lossPerDay;
                break;
            }
        }
    }

    cout << "\nJobs that will be scheduled (in order): ";
    for (const auto& jobID : scheduledJobs) {
        cout << jobID << " ";
    }

    cout << "\nTotal loss: " << totalLoss << endl;

    return 0;
}