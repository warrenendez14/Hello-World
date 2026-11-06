#include "traffic.h"

RedirectDecision handleVisit(const std::string& referrer) {

    // 1. Identification de la source
    TrafficSource source = detectSource(referrer);

    // 2. Choix de la destination
    std::string destination =
        chooseDestination(source);

    // 3. Enregistrement de la visite
    recordVisit(source, destination);

    // 4. Préparation de la décision
    RedirectDecision decision;

    decision.source = source;
    decision.destination = destination;

    return decision;
}
