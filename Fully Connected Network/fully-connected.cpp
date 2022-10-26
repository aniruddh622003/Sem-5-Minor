#include "fully-connected.hpp"
#include "../Matrix/matrix.hpp"
#include "activations.hpp"
#include "loss.hpp"

int main()
{
    // Define input and output
    std::vector<std::vector<float>> network_input = {{1.1, 20, 5}};
    std::vector<std::vector<float>> network_output = {{1, 20, 1, 4, 2}};

    // Create a network
    int in = 3, out = 3;
    std::vector<std::vector<float>> layer_1 = inititaliseLayer(3, 3);
    std::vector<std::vector<float>> layer_2 = inititaliseLayer(3, 5);

    std::vector<std::vector<float>> layer_1_in, layer_1_net, layer_1_out, layer_2_in, layer_2_net, layer_2_out;
    float loss_simple, loss_mse;
    std::vector<std::vector<float>> layer_2_loss, layer_2_change, layer_1_loss, layer_1_change;

    for (int i = 0; i < 10; i++)
    {
        // Feed Forward
        // Layer 1
        layer_1_in = network_input;
        layer_1_in[0].insert(layer_1_in[0].begin(), 1);
        layer_1_net = layerForward(layer_1_in, layer_1, 1, in + 1, out);
        layer_1_out = linear(layer_1_net, 1, out);

        // Layer 2
        layer_2_in = layer_1_out;
        layer_2_in[0].insert(layer_2_in[0].begin(), 1);
        layer_2_net = layerForward(layer_2_in, layer_2, 1, 4, 5);
        layer_2_out = linear(layer_2_net, 1, 5);

        // Loss
        loss_simple = simpleLoss(1, 5, layer_2_out, network_output);
        loss_mse = MSELoss(1, 5, layer_2_out, network_output);

        print_matrix(1, 5, layer_2_out);

        std::cout
            << "\nPass " << i + 1 << " -> "
            << "\n";
        std::cout << "Loss (Simple) -> " << loss_simple << "\n";
        std::cout << "Loss (MSE) -> " << loss_mse << "\n";

        // Weight updation && Backpropagation
        layer_2_loss = create_loss_vector(1, 5, loss_simple);

        layer_2_change = getChangeMatrix(4, 5, layer_2_loss, layer_2_in, 0.0001, 'a');
        // layer_1_loss = backpropError(4, 5, layer_2, layer_2_loss, 'a');

        // layer_1_change = getChangeMatrix(4, 3, layer_1_loss, layer_1_in, 0.0001, 'a');

        // layer_1 = add_matrix(4, 3, layer_1, layer_1_change);
        layer_2 = add_matrix(4, 5, layer_2, layer_2_change);
    }

    return 0;
}