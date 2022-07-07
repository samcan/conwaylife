#ifndef _CONWAYLIFEARRAY_H_
#define _CONWAYLIFEARRAY_H_

#include <vector>

enum ConwayLifeStatus { alive = true, dead = false };

class ConwayLife {
public:
    ConwayLife(const int x, const int y) : m_board(std::vector<ConwayLifeStatus>(x*y, ConwayLifeStatus::dead)), m_size_x(x), m_size_y(y), m_generation(0) {}
    ~ConwayLife() {
        // since we're dealing with a vector destruction is auto-taken care of
    }

    inline auto SizeX() const -> int { return m_size_x; }
    inline auto SizeY() const -> int { return m_size_y; }
    inline auto GenerationNum() const -> int { return m_generation; }

    auto IsAlive(const int x, const int y) const -> ConwayLifeStatus;
    void SetAlive(const int x, const int y);
    void SetDead(const int x, const int y);
    void SetStatus(const int x, const int y, const ConwayLifeStatus status);
    void CalcNextGeneration();

    // instead of using a 2D array we're using a 1D array and indexing
    // into the appropriate element
    std::vector<ConwayLifeStatus> m_board;
private:
    int m_size_x;
    int m_size_y;
    int m_generation;

    auto CalcNewCellState(const int x, const int y) const -> ConwayLifeStatus;
    auto CountAliveNeighbors(const int x, const int y) const -> int;

    inline auto Index(const int x, const int y) const -> int { return y * SizeX() + x; }
};


#endif