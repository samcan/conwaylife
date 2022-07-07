#ifndef _CONWAYLIFEARRAY_H_
#define _CONWAYLIFEARRAY_H_

#include <vector>

class ConwayLife {
private:
    int m_size_x;
    int m_size_y;
    int m_generation = 0;

    bool CalcNewCellState(const int x, const int y) const;
    int CountAliveNeighbors(const int x, const int y) const;

    inline int Index(const int x, const int y) const;
public:
    ConwayLife(const int x, const int y);
    ~ConwayLife();

    bool IsAlive(const int x, const int y) const;
    void SetAlive(const int x, const int y);
    void SetDead(const int x, const int y);

    auto GenerationNum() const -> int { return m_generation; }

    void CalcNextGeneration();

    auto SizeX() const -> int { return m_size_x; }
    auto SizeY() const -> int { return m_size_y; }


    // instead of using a 2D array we're using a 1D array and indexing
    // into the appropriate element
    std::vector<bool> m_board;
};


#endif