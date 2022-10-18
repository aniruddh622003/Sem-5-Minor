#include "fully-connected.hpp"
#include "../Matrix/matrix.hpp"
#include "activations.hpp"

int main()
{
    int in = 3, out = 3;
    std::vector<std::vector<float>> layer_1 = inititaliseLayer(3, 3);
    std::vector<std::vector<float>> layer_1_in = {{1.1, 20, 5}};
    layer_1_in[0].insert(layer_1_in[0].begin(), 1);
    std::vector<std::vector<float>> layer_1_net = layerForward(layer_1_in, layer_1, 1, in + 1, out);
    std::vector<std::vector<float>> layer_1_out = linear(layer_1_net, 1, out);
    std::vector<std::vector<float>> layer_2 = inititaliseLayer(3, 1);
    std::vector<std::vector<float>> layer_2_in = layer_1_out;
    layer_2_in[0].insert(layer_2_in[0].begin(), 1);
    std::vector<std::vector<float>> layer_2_net = layerForward(layer_2_in, layer_2, 1, in + 1, 1);
    std::vector<std::vector<float>> layer_2_out = linear(layer_2_net, 1, 1);
    print_matrix(1, out + 1, layer_1_in);
    print_matrix(1, out + 1, layer_2_in);
    print_matrix(1, 1, layer_2_out);
    return 0;
}