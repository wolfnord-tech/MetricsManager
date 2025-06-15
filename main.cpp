#include <chrono>
#include <iostream>
#include <thread>
#include "control/metricsmanager.h"
#include "data/timedata.h"
#include "data/metrics.h"
#include "control/eventprocessor.h"
using namespace std;

int main() {
    EventProcessor eventProcessor;
    MetricsManager metricsManager("test");
    TimeData timedata;
    vector<Metrics> metrics;

    eventProcessor.AddEvent([&]() {
        cout << "Work together 1\t";
        cout << endl << "Starting the first thread" << endl;
        string timestamp = timedata.capture_current_time();

        Metrics a("CPU", 0.97);
        Metrics b("HTTP requests RPS", 42);
        Metrics c("RAID health", 0.87);

        metrics.push_back(a);
        metrics.push_back(b);
        metrics.push_back(c);

        metricsManager.collectMetrics(timestamp, metrics);

        cout << "Collect 1" << endl;

        timestamp = timedata.capture_current_time();

        metrics[0].setMetrics("CPU", 1.12);
        metrics[1].setMetrics("HTTP requests RPS", 30);
        metrics[2].setMetrics("RAID health", 0.865);
        
        metricsManager.collectMetrics(timestamp, metrics);

        cout << "Collect 2" << endl;

        timestamp = timedata.capture_current_time();

        metrics[0].setMetrics("CPU", 1.87);
        metrics[1].setMetrics("HTTP requests RPS", 50);
        metrics[2].setMetrics("RAID health", 0.84);
        
        metricsManager.collectMetrics(timestamp, metrics);

        cout << "Collect 3" << endl;
        timestamp = timedata.capture_current_time();

        metrics[0].setMetrics("CPU", 1.2);
        metrics[1].setMetrics("HTTP requests RPS", 55);
        metrics[2].setMetrics("RAID health", 0.82);

        this_thread::sleep_for(chrono::milliseconds(15));
        
        metricsManager.collectMetrics(timestamp, metrics);

        cout << "Collect 4" << endl;
        timestamp = timedata.capture_current_time();

        metrics[0].setMetrics("CPU", 1.5);
        metrics[1].setMetrics("HTTP requests RPS", 34);
        metrics[2].setMetrics("RAID health", 0.8);
        
        metricsManager.collectMetrics(timestamp, metrics);

        cout << "Collect 5" << endl;
        timestamp = timedata.capture_current_time();

        metrics[0].setMetrics("CPU", 1);
        metrics[1].setMetrics("HTTP requests RPS", 20);
        metrics[2].setMetrics("RAID health", 0.79);
        
        metricsManager.collectMetrics(timestamp, metrics);

        cout << "Collect 6" << endl;
    });

    eventProcessor.AddEvent([&]() {
        cout << "Work together 2\t";
        this_thread::sleep_for(chrono::milliseconds(5));
        cout << "Starting the second thread" << endl;
        metricsManager.saveMetrics();
        this_thread::sleep_for(chrono::milliseconds(15));
        metricsManager.saveMetrics();
    });

    eventProcessor.ProcessEvents();

    return 0;
}