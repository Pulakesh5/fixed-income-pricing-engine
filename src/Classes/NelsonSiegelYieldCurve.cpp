#include <iostream>
#include <vector>
#include <cmath>

class NelsonSiegelYieldCurve {
public:
    NelsonSiegelYieldCurve(double beta0, double beta1, double beta2, double lambda)
        : beta0_(beta0), beta1_(beta1), beta2_(beta2), lambda_(lambda) 
        {

        }

    // Calculate the yield for a given time to maturity
    double calculateYield(double maturity) const
    {
        return beta0_ + (beta1_ * (1 - std::exp(-maturity / lambda_)) / (maturity / lambda_)) +
               (beta2_ * ((1 - std::exp(-maturity / lambda_)) / (maturity / lambda_) - std::exp(-maturity / lambda_)));
    }

    // Calculate the yields for a range of maturities
    std::vector<double> calculateYields(const std::vector<double>& maturities) const 
    {
        std::vector<double> yields;
        for (double maturity : maturities) 
        {
            yields.push_back(calculateYield(maturity));
        }
        return yields;
    }

private:
    double beta0_;
    double beta1_;
    double beta2_;
    double lambda_;
};