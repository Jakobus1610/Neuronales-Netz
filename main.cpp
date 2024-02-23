#include <cmath>

struct Node
{
    double value;
    double bias;
};

struct NodeLayer
{
    int numNodes;
    Node *nodes;
};

struct Weight
{
    double weight;
};


struct WeightRow
{
    int numWeights;
    Weight *weights;
};
// weight
struct WeightLayer
{
    int numWeightRows;
    WeightRow *weightRows;
};

struct Network
{
    int numNodeLayers;
    NodeLayer *nodeLayers;
    int numWeightsLayers;
    WeightLayer *weightLayers;
};

const double EULER = 2.71828182845904523536;

void initNetwork(Network &network, int numLayers, int numRows[])
{
    network.numNodeLayers = numLayers;
    network.nodeLayers = new NodeLayer[numLayers];
    for (int i = 0; i < numLayers; i++)
    {
        network.nodeLayers[i].numNodes = numRows[i];
        network.nodeLayers[i].nodes = new Node[numRows[i]];
    }

    network.numWeightsLayers = numLayers;
    network.weightLayers = new WeightLayer[numLayers];
    for (int i = 0; i < numLayers; i++)
    {
        network.weightLayers[i].numWeightRows = numRows[i];
        network.weightLayers[i].weightRows = new WeightRow[numRows[i]];
        int weights = i < network.numNodeLayers ? network.nodeLayers[i+1].numNodes : 0;
        for(int j = 0; j < numRows[i]; j++)
        {
            network.weightLayers[i].weightRows[j].numWeights = network.nodeLayers[i+1].numNodes;
            network.weightLayers[i].weightRows[j].weights = new Weight[network.nodeLayers[i+1].numNodes];
        }
    }
}

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
