#include <iostream>
#include <vector>
#include <cmath>

void home() {
    std::cout << "Polynomial Solver (Bisection Method)\n";
}

float f(std::vector<float>&, float, int);

int main() {
    int deg;
    std::vector<float> coeff;
    float x0, x1, x2, tol;  // Added 'tol' for tolerable error
    home();
    std::cout << "Enter the degree of the polynomial: ";
    std::cin >> deg;
    std::cout << "Enter the coefficients of the polynomial in order of their degree (highest first):\n";
    for (int i = deg; i >= 0; i--) {
        float temp;
        std::cin >> temp;
        coeff.push_back(temp);
    }
    std::cout << "Enter two initial guesses: ";
    std::cin >> x0 >> x1;
    std::cout << "Enter the tolerable error: ";
    std::cin >> tol;

    // Print table headers
    std::cout << "Iteration\t\tX0\t\tX1\t\tX2\t\tf(X2)\n";

    int i = 1;
    while (true) {
        x2 = (x0 + x1) / 2;
        float fx2 = f(coeff, x2, deg);
        std::cout << i << "\t\t" << x0 << "\t\t" << x1 << "\t\t" << x2 << "\t\t" << fx2 << "\n";
        i++;
        
        if (std::abs(x0 - x1) <= tol) {
            std::cout << "The answer is " << x2 << " with tolerable error " << tol << std::endl;
            break;
        }

        if (fx2 > 0) {
            x1 = x2;
        } else {
            x0 = x2;
        }
    }
    return 0;
}

float f(std::vector<float>& coeff, float inp, int deg) {
    float res = 0;
    for (auto c : coeff) {
        res += pow(inp, deg--) * c;
    }
    return res;
}

