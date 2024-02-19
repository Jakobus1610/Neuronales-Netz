#include <cmath>

const double EULER = 2.71828182845904523536;

struct Node
{
    double value;
    double bias;
};

double activationFunc(double value, double bias)
{
    return 1/(1+pow(EULER, -value + bias));
}

double evaluate(int NodeLayer, int NodeRow)
{
    double result;

}

int main()
{

}
