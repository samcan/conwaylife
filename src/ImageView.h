#ifndef _IMAGEVIEW_H_
#define _IMAGEVIEW_H_

#include <string>

#include "ConwayLifeArray.h"

class ImageView {
private:
    const static std::string StringAlive();
    const static std::string StringDead();
public:
    static void write(ConwayLifeArray *board);
};

#endif