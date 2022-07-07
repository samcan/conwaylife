#ifndef _IMAGEVIEW_H_
#define _IMAGEVIEW_H_

#include <string>

#include "ConwayLife.h"

class ImageView {
private:
    inline static std::string StringAlive();
    inline static std::string StringDead();
    inline static std::string CellString(ConwayLifeStatus status);
public:
    static void write(ConwayLife& board);
};

#endif