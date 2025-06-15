#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <map>
#include <vector>
#include "../data/metrics.h"
using namespace std;

class FileManager { // Отвечает за сохранение метрик в файл в текстовом виде
    private:
        string sourceFile;
    public:
        FileManager(string sourceFile) : sourceFile(sourceFile  + ".txt") {};

        string getSourceFile();

        void setSourceFile(string sourceFile);

        void save(map<string, vector<Metrics>>& metrics);
};

#endif