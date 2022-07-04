#ifndef _IMAGEVIEW_H_
#define _IMAGEVIEW_H_

#include <string>
#include <memory>

#include "ConwayLifeArray.h"

class ImageView {
private:
    const static std::string StringAlive();
    const static std::string StringDead();
public:
    static void write(std::shared_ptr<ConwayLifeArray> board);
};

#endif