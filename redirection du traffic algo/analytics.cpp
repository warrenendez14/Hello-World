#include "traffic.h"
#include <fstream>
#include <ctime>

TrafficSource detectSource(const std::string& referrer) {

    if (referrer.find("google.") != std::string::npos)
        return TrafficSource::GOOGLE;

    if (referrer.find("facebook.") != std::string::npos)
        return TrafficSource::FACEBOOK;

    if (referrer.find("tiktok.") != std::string::npos)
        return TrafficSource::TIKTOK;

    if (referrer.find("instagram.") != std::string::npos)
        return TrafficSource::INSTAGRAM;

    if (referrer.empty())
        return TrafficSource::DIRECT;

    return TrafficSource::OTHER;
}

std::string sourceToString(TrafficSource source) {

    switch (source) {

        case TrafficSource::GOOGLE:
            return "Google";

        case TrafficSource::FACEBOOK:
            return "Facebook";

        case TrafficSource::TIKTOK:
            return "TikTok";

        case TrafficSource::INSTAGRAM:
            return "Instagram";

        case TrafficSource::DIRECT:
            return "Direct";

        default:
            return "Other";
    }
}

void recordVisit(TrafficSource source,
                 const std::string& destination) {

    std::ofstream file("visits.csv", std::ios::app);

    if (!file.is_open())
        return;

    std::time_t now = std::time(nullptr);

    file << now << ","
         << sourceToString(source) << ","
         << destination << "\n";

    file.close();
}
