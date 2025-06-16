#ifndef METRICS_H
#define METRICS_H

#include <iostream>
#include <string>
using namespace std;

// Класс Metrics отвечает за объекты каждой метрики
class Metrics {
    protected:
        string from;
        float value;
    public:
        Metrics() : from("null"), value(0) {};

        Metrics(string from, float value): from(from), value(value) {};

        string getFrom();
        double getValue();

        void printMetrics();

        void setMetrics(string from, float value);

        string getMetrics();
};

#endif
