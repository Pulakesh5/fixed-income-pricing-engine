#include "DataInput/data_input.cc"
#include "Classes/NelsonSiegelYieldCurve.cpp"

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



    /* ----------NelsonSiegel Yield Curve control---------- */
    
    // Example parameters for the Nelson-Siegel model
    double beta0 = 0.03;
    double beta1 = -0.02;
    double beta2 = -0.01;
    double lambda = 2.0;

    // Create a Nelson-Siegel yield curve model
    NelsonSiegelYieldCurve curve(beta0, beta1, beta2, lambda);

    // Define a range of maturities (in years)
    std::vector<double> maturities = {1.0, 2.0, 3.0, 4.0, 5.0};

    // Calculate yields for the specified maturities
    std::vector<double> yields = curve.calculateYields(maturities);

    // Print the results
    std::cout << "Maturity (Years)\tYield (%)" << std::endl;
    for (int i = 0; i < maturities.size(); ++i) {
        std::cout << maturities[i] << "\t\t\t" << yields[i] * 100.0 << std::endl;
    }

    /* ---------------------------------------------------- */



    return 0; // Exit successfully
}