#include "FileReader.h"

namespace FileReader {

    fileReader::fileReader(std::string path, std::string filename) {

        eData_ = { 0,0,0,0 };
        path_ = path;
        fileName_ = filename;
        
    }

    void fileReader::readOneLine(bool& iseof) {

        if (!fileInitialised_) {
            std::string fullPath = path_ + fileName_;
            initialiseFile(fullPath);
        }

        if (myFile_.eof()) {
            iseof = true;
        }

        std::string str;
        std::getline(myFile_, str);
        getNumber(str);


    }

    void fileReader::initialiseFile(std::string fullPath) {

        myFile_.open(fullPath, std::ios::in);
        timeResolution_ = 1e6;
        fileInitialised_ = true;
    }

    void fileReader::getNumber_Legacy(double* numArray, std::string str) {

        std::string word;
        int i = 0;
        for (auto x : str) {
            if (x == ' ') {
                numArray[i] = atof(word.c_str());
                word = "";
                i++;
            }
            else {
                word = word + x;
            }
        }
        numArray[i] = atof(word.c_str());

    }

    void fileReader::getNumber(std::string str) {

        std::string word;
        int i = 0;
        for (auto x : str) {
            if (x == ' ') {
                switch (i) {
                case 0: {
                    // ts was encoded in microsecond (timeResolution = 1e6)
                    eData_.ts = uint64_t(timeResolution_ * atof(word.c_str()));
                    break;
                }
                case 1: {
                    eData_.x = std::stoi(word);
                    break;
                }
                case 2: {
                    eData_.y = std::stoi(word);
                    break;
                }
                default: {
                    eData_.polarity = std::stoi(word);
                    break;
                }
                }
                word = "";
                i++;
            }
            else {
                word = word + x;
                eData_.polarity = std::stoi(word);
            }
        }
    }
}