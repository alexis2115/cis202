#include <iostream>
#include <vector>
#include <string>

class Mountain {
private:
    std::string name;
    std::string country;
    double elevation;

public:
    // Constructor
    Mountain(std::string name, std::string country, double elevation) {
        this->name = name;
        this->country = country;
        this->elevation = elevation;
    }

    // Getters and Setters
    std::string getName() const {
        return name;
    }

    std::string getCountry() const {
        return country;
    }

    double getElevation() const {
        return elevation;
    }

    void setName(std::string name) {
        this->name = name;
    }

    void setCountry(std::string country) {
        this->country = country;
    }

    void setElevation(double elevation) {
        this->elevation = elevation;
    }

    // Convert elevation from feet to meters
    double toMeters() const {
        return elevation / 3.2808;
    }
};

// Find the mountain with the minimum elevation
Mountain minElevation(const std::vector<Mountain>& mountains) {
    Mountain minMountain = mountains[0];
    for (const auto& mountain : mountains) {
        if (mountain.getElevation() < minMountain.getElevation()) {
            minMountain = mountain;
        }
    }
    return minMountain;
}

int main() {
    std::vector<Mountain> mountains;

    // Create Mountain objects and add them to the vector
    mountains.push_back(Mountain("Chimborazo", "Ecuador", 20549));
    mountains.push_back(Mountain("Matterhorn", "Switzerland", 14692));
    mountains.push_back(Mountain("Olympus", "Greece (Macedonia)", 9573));
    mountains.push_back(Mountain("Everest", "Nepal", 29029));
    mountains.push_back(Mountain("Mount Marcy - Adirondacks", "United States", 5344));
    mountains.push_back(Mountain("Mount Mitchell - Blue Ridge", "United States", 6684));
    mountains.push_back(Mountain("Zugspitze", "Switzerland", 9719));

    // Iterate over the mountains and print their details
    for (const auto& mountain : mountains) {
        std::cout << "Mountain: " << mountain.getName() << std::endl;
        std::cout << "Country: " << mountain.getCountry() << std::endl;
        std::cout << "Elevation (feet): " << mountain.getElevation() << std::endl;
        std::cout << "Elevation (meters): " << mountain.toMeters() << std::endl;
        std::cout << std::endl;
    }

    // Find the mountain with the minimum elevation
    Mountain shortestMountain = minElevation(mountains);
    std::cout << "Shortest Mountain: " << shortestMountain.getName() << std::endl;
    std::cout << "Elevation (feet): " << shortestMountain.getElevation() << std::endl;

    return 0;
}
