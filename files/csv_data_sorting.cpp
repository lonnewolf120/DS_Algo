#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>

// Function to split a comma-separated string into a vector of strings
std::vector<std::string> splitString(const std::string& input) {
    std::vector<std::string> result;
    std::istringstream stream(input);
    std::string token;

    while (std::getline(stream, token, ',')) {
        result.push_back(token);
    }

    return result;
}

int main() {
    // Input and output file names
    std::string inputFile = "input.csv";
    std::string outputFile = "output.csv";

    // Open the input CSV file
    std::ifstream inFile(inputFile);
    if (!inFile.is_open()) {
        std::cerr << "Error opening input file." << std::endl;
        return 1;
    }

    // Open the output CSV file
    std::ofstream outFile(outputFile);
    if (!outFile.is_open()) {
        std::cerr << "Error opening output file." << std::endl;
        inFile.close();
        return 1;
    }

    // Map to store common strings and their corresponding values
    std::unordered_map<std::string, std::string> commonStrings;

    // Process the header row
    std::string header;
    std::getline(inFile, header);
    outFile << header << ",CommonColumn\n";

    // Process each row in the input CSV file
    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream rowStream(line);
        std::string cell;
        std::vector<std::string> values;

        // Read the first three columns (B, C, D)
        for (int i = 0; i < 3; ++i) {
            std::getline(rowStream, cell, ',');
            values.push_back(cell);
        }

        // Read the comma-separated strings from columns D, E, F
        std::getline(rowStream, cell, ',');
        std::vector<std::string> strings = splitString(cell);

        // Process each string and update the commonStrings map
        for (const std::string& str : strings) {
            if (commonStrings.find(str) == commonStrings.end()) {
                commonStrings[str] = values[2];  // Store the corresponding value from column D
            } else {
                // If the string is already in the map, update the corresponding value
                commonStrings[str] += "," + values[2];
            }
        }

        // Write the original row to the output CSV file
        outFile << line;

        // Add the common column with corresponding values
        for (const auto& entry : commonStrings) {
            outFile << "," << entry.second;
        }

        outFile << "\n";

        // Clear the commonStrings map for the next row
        commonStrings.clear();
    }

    // Close the files
    inFile.close();
    outFile.close();

    std::cout << "Conversion complete. Output written to " << outputFile << std::endl;

    return 0;
}
