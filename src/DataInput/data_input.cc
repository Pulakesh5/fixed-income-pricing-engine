#include "data_input.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
std::vector<std::vector<std::string>> DataInputReader::readDataFromCSV(const std::string &filePath)
{
    std::vector<std::vector<std::string>> data;
    // open the CSV file
    std::ifstream file(filePath);

    // check that the file is open
    if (!file.is_open())
    {
        std::cerr << "Could not open the file - '"
                  << filePath << "'" << std::endl;
        return data;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::vector<std::string> row;
        std::stringstream lineStream(line);
        std::string cell;

        while (std::getline(lineStream, cell, ','))
        {
            row.push_back(cell);
        }
        data.push_back(row);
    }

    file.close();
    return data;
}