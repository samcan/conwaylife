#include <iostream>
#include <fstream>
#include <string>
#include <memory>

#include "ImageView.h"
#include "ConwayLife.h"

void ImageView::write(ConwayLife& board)
{
    // write out ppm of results
    std::string outfilename("output" + std::to_string(board.GenerationNum()) + ".ppm");
    std::ofstream outfile(outfilename, std::ios::binary);

    // ppm file header - P3 for 0-255 RGB as a text file
    outfile << "P3" << '\n';
    // image dimensions - width X height
    int image_width(board.SizeX());
    int image_height(board.SizeY());
    outfile << image_width << " " << image_height << '\n';

    int max_rgb_val(255);
    outfile << max_rgb_val << '\n';

    // image data -- each pixel in image is an RGB triplet.
    // can have line breaks or just spaces in between each
    // triplet

    // note that I tested code where I did one big loop rather than
    // two nested loops but the time savings were minimal so I felt
    // the clearer code was the better choice
    for (int y = 0; y < image_height; y++)
    {
        for (int x = 0; x < image_width; x++)
        {
            outfile << CellString(board.IsAlive(x, y)) << '\n';
        }
    }
}

inline std::string ImageView::CellString(ConwayLifeStatus status) {
    if (status == ConwayLifeStatus::alive) {
        return StringAlive();
    } else {
        return StringDead();
    }
}

inline std::string ImageView::StringAlive() {
    return "0 0 0";
}

inline std::string ImageView::StringDead() {
    return "255 255 255";
}