#include "traffic.h"
#include <fstream>
#include <iostream>
#include <string>

TrafficStats getStatistics() {

    TrafficStats stats;

    std::ifstream file("visits.csv");

    if (!file.is_open())
        return stats;

    std::string timestamp;
    std::string source;
    std::string destination;

    while (std::getline(file, timestamp, ',') &&
           std::getline(file, source, ',') &&
           std::getline(file, destination)) {

        stats.totalVisits++;

        if (source == "Google")
            stats.googleVisits++;

        else if (source == "Facebook")
            stats.facebookVisits++;

        else if (source == "TikTok")
            stats.tiktokVisits++;

        else if (source == "Instagram")
            stats.instagramVisits++;

        else if (source == "Direct")
            stats.directVisits++;

        else
            stats.otherVisits++;
    }

    return stats;
}

void displayStatistics() {

    TrafficStats stats = getStatistics();

    std::cout << "\n";
    std::cout << "==============================\n";
    std::cout << "   WARREN TRAFFIC ENGINE\n";
    std::cout << "==============================\n";

    std::cout << "Total des visites : "
              << stats.totalVisits << "\n";

    std::cout << "Google : "
              << stats.googleVisits << "\n";

    std::cout << "Facebook : "
              << stats.facebookVisits << "\n";

    std::cout << "TikTok : "
              << stats.tiktokVisits << "\n";

    std::cout << "Instagram : "
              << stats.instagramVisits << "\n";

    std::cout << "Direct : "
              << stats.directVisits << "\n";

    std::cout << "Autres : "
              << stats.otherVisits << "\n";

    std::cout << "==============================\n";
}
