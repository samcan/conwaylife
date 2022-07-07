#include <iostream>
#include <fstream>
#include <string>
#include <memory>

#include "ImageView.h"
#include "ConwayLifeArray.h"

void ImageView::write(std::shared_ptr<ConwayLifeArray> board)
{
    // write out ppm of results
    std::string outfilename("output" + std::to_string(board->GenerationNum()) + ".ppm");
    std::ofstream outfile(outfilename, std::ios::binary);

    // ppm file header - P3 for 0-255 RGB as a text file
    outfile << "P3" << '\n';
    // image dimensions - width X height
    int imagewidth(board->SizeX());
    int imageheight(board->SizeY());

    outfile << imagewidth << " " << imageheight << '\n';
    outfile << "255" << '\n';

    // image data -- each pixel in image is an RGB triplet.
    // can have line breaks or just spaces in between each
    // triplet
    for (int y = 0; y < imageheight; y++)
    {
        for (int x = 0; x < imagewidth; x++)
        {
            if (board->IsAlive(x, y)) {
                outfile << StringAlive() << '\n';
            } else {
                outfile << StringDead() << '\n';
            }
        }
    }
}

std::string ImageView::StringAlive() {
    return "0 0 0";
}

std::string ImageView::StringDead() {
    return "255 255 255";
}