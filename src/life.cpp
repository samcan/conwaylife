#include <iostream>
#include <fstream>
#include <string>
#include <memory>

#include "ConwayLifeArray.h"
#include "ImageView.h"

int main() {
    std::shared_ptr<ConwayLifeArray> conway = std::make_shared<ConwayLifeArray>(100, 100);

    // set pattern of blinker
    conway->SetAlive(1, 0);
    conway->SetAlive(1, 1);
    conway->SetAlive(1, 2);

    // set pattern of spaceship
    conway->SetAlive(5, 5);
    conway->SetAlive(7, 5);
    conway->SetAlive(6, 6);
    conway->SetAlive(7, 6);
    conway->SetAlive(6, 7);
    
    // write state
    ImageView::write(conway);

    for (int gen=0; gen<10; gen++) {
        // advance generation and write image
        conway->CalcNextGeneration();
        ImageView::write(conway);
    }

    return 0;
}

// we need to represent the board in memory somehow, and then tick it through
// each generation. Then we can either write out images for each generation or
// write out the final result

// Model
// - stores current state
//
// Controller
// - requests new generation
//
// View
// - write out image file of state