#include "metricsmanager.h"
#include "filemanager.h"
#include <string>
#include <vcruntime.h>
#include <vector>
#include <iostream>
using namespace std;

void MetricsManager::collectMetrics(string timestamp, vector<Metrics> metrics) {
    if (timestamp != last_timestamp && this->metrics.empty()) // Значение не совпадает с прошлым и массив пустой
        this->metrics[timestamp] = metrics;
    else if (!this->metrics.empty()) // Массив не пустой
        this->metrics[timestamp] = metrics;
    last_timestamp = timestamp;
    cout << timestamp << endl;
}

void MetricsManager::saveMetrics() {
    FileManager filemanager(fileName);
    filemanager.save(metrics);
}
