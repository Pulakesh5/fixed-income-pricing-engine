#include <vector>
#include <string>

class DataInputReader
{
public:
    DataInputReader() = default;
    ~DataInputReader() = default;

    std::vector<std::vector<std::string>> readDataFromCSV(const std::string &filePath);
    std::vector<std::vector<std::string>> readDataFromUseInput();
};