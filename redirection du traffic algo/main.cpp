#include "traffic.h"
#include <iostream>
#include <string>

int main() {

    int choix;

    std::cout << "\n";
    std::cout << "WARREN TRAFFIC ENGINE\n";
    std::cout << "----------------------\n";

    std::cout << "1. Tester une visite\n";
    std::cout << "2. Afficher les statistiques\n";

    std::cout << "\nVotre choix : ";
    std::cin >> choix;

    if (choix == 1) {

        std::string referrer;

        std::cout << "Source du visiteur : ";
        std::cin >> referrer;

        RedirectDecision result =
            handleVisit(referrer);

        std::cout << "\nSource identifiee : "
                  << sourceToString(result.source);

        std::cout << "\nDestination : "
                  << result.destination << "\n";
    }

    else if (choix == 2) {

        displayStatistics();

    }

    else {

        std::cout << "Choix invalide.\n";

    }

    return 0;
}
