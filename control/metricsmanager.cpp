#include "metricsmanager.h"
#include "filemanager.h"
#include <string>
#include <vcruntime.h>
#include <vector>
#include <iostream>
using namespace std;

void MetricsManager::collectMetrics(string timestamp, vector<Metrics> metrics) {
    this->metrics[timestamp] = metrics;
    cout << timestamp << endl;
}

void MetricsManager::saveMetrics() {
    FileManager filemanager(fileName);
    filemanager.save(metrics);
}
