#include <iostream>

class Farm {

    // I must use unsigned long long int because area for max possible input (INT_MAX) equals 576460751766552576
    int fence_length;
    unsigned long long int a;
    unsigned long long int b;
    unsigned long long int area_of_farm;


    void optimize_area() {
        /* 2a + b = fence_length | -2a
           b = fence_length - 2a
           a * b --> MAX
           -2a^2 + fence_length * a --> MAX
           a = -fence_length/-4 */

        //temporary double for more precise calculation
        double temp_a = (double) (fence_length) / 4;
        double temp_b = (double) (fence_length) - 2 * temp_a;
        a = (int) temp_a;
        b = (int) temp_b;

        if (fence_length - a - a - b == 1) {
            b++;
        } else if (fence_length - a - a - b == 2) {
            a++;
        }

        area_of_farm = a * b;
    }


public:
    void printResults() const {
        std::cout << "Fence length: " << fence_length << "\na: " << a << "\nb: " << b << "\narea: " << area_of_farm;
    }

    explicit Farm(int fence_length) {
        this->fence_length = fence_length;
        a = 0;
        b = 0;
        area_of_farm = 0;
        optimize_area();

    }
};

class InputController {
public:
    static int takeFenceLength() {
        int fence_length;
        while (true) {
            std::cout << "\nEnter the length of the fence:";
            std::cin >> fence_length;

            //Check cin is a string and cin is out of range cases. Float are implicit converted to int.
            if (std::cin.good()) {
                if (fence_length >= 3) {
                    return fence_length;
                } else {
                    std::cerr << "Value of length must be min 3 and max " << INT_MAX;
                }
            } else {
                std::cerr << "Length of fence must be a number and be lower or equal of " << INT_MAX;
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
            //There can be some order problems in console because std::cerr and std::cout are different
            // streams, and they are not synchronized.
        }
    }


    static void algorithmActivate() {
        // check activation word and handle new line input
        std::string start;
        const std::string activation_word = "RUN";
        while (start != activation_word || start.empty()) {
            std::cout << "Type RUN to start:";
            std::getline(std::cin, start);
        }

    }
};


int main() {
    InputController::algorithmActivate();
    Farm farm = Farm(InputController::takeFenceLength());
    farm.printResults();

    return 0;
}
