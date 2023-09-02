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

int main()
{
    // Provide the path to your CSV file here
    std::string filePath = "../../data/datafeed.csv";

    // Call the function to read data from the CSV file
    DataInputReader reader;
    std::vector<std::vector<std::string>> csvData = reader.readDataFromCSV(filePath);

    // Check if data was successfully read
    if (csvData.empty())
    {
        std::cerr << "No data read from the CSV file." << std::endl;
        return 1; // Exit with an error code
    }

    // Display the read data (for demonstration purposes)
    for (const auto &row : csvData)
    {
        for (const auto &cell : row)
        {
            std::cout << cell << "\t";
        }
        std::cout << std::endl;
    }

    return 0; // Exit successfully
}