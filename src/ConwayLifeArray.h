#ifndef _CONWAYLIFEARRAY_H_
#define _CONWAYLIFEARRAY_H_

#include "ConwayLife.h"

class ConwayLifeArray : public ConwayLife {
private:
    int m_size_x;
    int m_size_y;

    bool CalcNewCellState(const int x, const int y) const;
    int CountAliveNeighbors(const int x, const int y) const;

    inline int Index(const int x, const int y) const;
public:
    ConwayLifeArray(const int x, const int y);
    ~ConwayLifeArray();

    bool IsAlive(const int x, const int y) const;
    void SetAlive(const int x, const int y);
    void SetDead(const int x, const int y);

    

    void CalcNextGeneration();

    int SizeX() const;
    int SizeY() const;

    // instead of using a 2D array we're using a 1D array and indexing
    // into the appropriate element
    bool *m_board;
};


#endif