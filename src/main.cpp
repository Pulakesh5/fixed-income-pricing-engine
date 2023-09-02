#include "DataInput/data_input.cc"
int main()
{
    // Provide the path to your CSV file here
    std::string filePath = "../data/datafeed.csv";

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