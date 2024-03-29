//
// Created by Oliver Epper on 19.01.24.
//

#include <stunning.h>
#include <iostream>

int main(int argc, char *argv[]) {
    try {
        auto result = perform_binding_request("stun1.l.google.com", 19302);
        if (result.has_value()) {
            if (argc > 1 && std::strcmp(argv[1], "--ip") == 0)
                std::cout << result.value().value;
            else
                std::cout << result.value() << std::endl;
        }
    } catch (const stunning::exception& e) {
        std::cerr << e.what();
    }

    return EXIT_SUCCESS;
}