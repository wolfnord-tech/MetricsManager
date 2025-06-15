#include "filemanager.h"
#include <fstream>
#include <vector>
using namespace std;

string FileManager::getSourceFile() {
    return sourceFile;
}

void FileManager::setSourceFile(string sourceFile) {
    this->sourceFile = sourceFile + ".txt";
}

void FileManager::save(map<string, vector<Metrics>>& metrics) {
    ofstream file(sourceFile, ios::app);
    string text;

    cout << getSourceFile() << endl;

    cout << "Before saving" << endl;

    for (auto item : metrics) {
        cout << item.first;
        for (size_t i = 0; i < item.second.size(); ++i)
            cout << item.second[i].getMetrics();   
        cout << endl; 
    }

    cout << "Saving file" << endl;

    if (file.is_open())
        for (auto item : metrics) {
        file << item.first;
        for (size_t i = 0; i < item.second.size(); ++i)
            file << item.second[i].getMetrics();  
        file << endl;   
    }
        
    file.close();

    for (auto item : metrics)
        item.second.clear();
    metrics.clear();

    cout << "After saving" << endl;

    for (auto item : metrics) {
        cout << item.first;
        for (size_t i = 0; i < item.second.size(); ++i)
            cout << item.second[i].getMetrics();   
        cout << endl; 
    }

    cout << "The file has been created successfully!" << endl;
}