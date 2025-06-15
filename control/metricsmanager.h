#ifndef METRICSMANAGER_H
#define METRICSMANAGER_H

#include "../data/metrics.h"
#include <vector>
#include <map>
using namespace std;

class MetricsManager { // Отвечает за сбор метрик
    private:
        map<string, vector<Metrics>> metrics;
        string fileName;
    public:
        MetricsManager(string fileName) : fileName(fileName) {}; 

        void collectMetrics(string timestamp, vector<Metrics> metrics);

        void saveMetrics();
};

#endif