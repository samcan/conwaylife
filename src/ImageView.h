#ifndef _IMAGEVIEW_H_
#define _IMAGEVIEW_H_

#include <string>
#include <memory>

#include "ConwayLife.h"

class ImageView {
private:
    static std::string StringAlive();
    static std::string StringDead();
public:
    static void write(std::shared_ptr<ConwayLife> board);
};

#endif