#ifndef TRAFFIC_H
#define TRAFFIC_H

#include <string>

enum class TrafficSource {
    GOOGLE,
    FACEBOOK,
    TIKTOK,
    INSTAGRAM,
    DIRECT,
    OTHER
};

struct RedirectDecision {
    TrafficSource source;
    std::string destination;
};

struct TrafficStats {
    int totalVisits = 0;
    int googleVisits = 0;
    int facebookVisits = 0;
    int tiktokVisits = 0;
    int instagramVisits = 0;
    int directVisits = 0;
    int otherVisits = 0;
};

// ANALYTICS
TrafficSource detectSource(const std::string& referrer);
void recordVisit(TrafficSource source,
                 const std::string& destination);

// ROUTER
std::string chooseDestination(TrafficSource source);

// TRAFFIC ENGINE
RedirectDecision handleVisit(const std::string& referrer);

// STATISTICS
TrafficStats getStatistics();
void displayStatistics();

std::string sourceToString(TrafficSource source);

#endif
