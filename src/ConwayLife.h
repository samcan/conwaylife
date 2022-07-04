#ifndef _CONWAYLIFE_H_
#define _CONWAYLIFE_H_

class ConwayLife {
protected:
    int generation = 0;
public:
    const int GenerationNum() {
        return generation;
    }
};

#endif