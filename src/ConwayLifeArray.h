#ifndef _CONWAYLIFEARRAY_H_
#define _CONWAYLIFEARRAY_H_

#include "ConwayLife.h"

class ConwayLifeArray : public ConwayLife {
private:
    int m_size_x;
    int m_size_y;

    const bool CalcNewCellState(const int x, const int y);
    const int CountAliveNeighbors(const int x, const int y);

    inline const int Index(const int x, const int y);
public:
    ConwayLifeArray(const int x, const int y);
    ~ConwayLifeArray();

    const bool IsAlive(const int x, const int y);
    void SetAlive(const int x, const int y);
    void SetDead(const int x, const int y);

    

    void CalcNextGeneration();

    const int SizeX();
    const int SizeY();

    // instead of using a 2D array we're using a 1D array and indexing
    // into the appropriate element
    bool *m_board;
};


#endif