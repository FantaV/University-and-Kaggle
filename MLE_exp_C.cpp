#include <iostream>
#include <vector>
#include <cmath>    // log, exp

// log-likelihood per lambda dato un campione
double log_like(double lambda, const std::vector<double> & sample) {
    double logL = 0.0;

    for (double x : sample) {
        // densità esponenziale: f(x|λ) = λ * exp(-λ x)
        // log f = log(λ) - λx
        logL += std::log(lambda) - lambda * x;
    }

    return logL;
}

int main() {
    // campione
    std::vector<double> sample = {1.34, 3.56, 2.01};

    double best_lambda = 0.0;
    double best_logL = -INFINITY;

    // cerca il massimo nel range [0.001, 10]
    for (double lambda = 0.001; lambda <= 10; lambda += 0.001) {

        double L = log_like(lambda, sample);

        if (L > best_logL) {
            best_logL = L;
            best_lambda = lambda;
        }
    }

    std::cout << "MLE per lambda = " << best_lambda << std::endl;
    std::cout << "Log-likelihood massima = " << best_logL << std::endl;

    return 0;
}