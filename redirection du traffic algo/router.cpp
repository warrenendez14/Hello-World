#include "traffic.h"

std::string chooseDestination(TrafficSource source) {

    const std::string homepage =
        "https://sites.google.com/view/warren-endez";

    switch (source) {

        case TrafficSource::GOOGLE:
            return homepage;

        case TrafficSource::FACEBOOK:
            return homepage;

        case TrafficSource::TIKTOK:
            return homepage;

        case TrafficSource::INSTAGRAM:
            return homepage;

        case TrafficSource::DIRECT:
            return homepage;

        default:
            return homepage;
    }
}
