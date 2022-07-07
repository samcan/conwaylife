// this is the model for the Conway Game of Life

// we currently store as a 2D array where false == dead and true == alive

// when a new generation is requested, loop through all cells and update
// their state on a new copy. Once done, then set board to new board

// presume all cells outside array are dead (I'll probably have board wrap
// at some point)

// rules (from Wikipedia)
// Any live cell with two or three live neighbours survives.
// Any dead cell with three live neighbours becomes a live cell.
// All other live cells die in the next generation. Similarly, all other dead cells stay dead.

#include <algorithm>
#include <iostream>
#include <memory>

#include "ConwayLife.h"


auto ConwayLife::IsAlive(const int x, const int y) const -> ConwayLifeStatus {
    if (x < 0 || x >= SizeX() || y < 0 || y >= SizeY()) {
        // we've been given an out of bounds cell so we'll wrap around to
        // the other side
        int new_x(x);
        int new_y(y);

        // can't do a straight modulus operation as if the x or y is negative,
        // since C++11 the result will also be negative. As we're trying to loop
        // around positive I add the array size to x or y to get the new_x or
        // new_y
        if (x >= SizeX()) {
            new_x = x % SizeX();
        } else if (x < 0) {
            new_x = x + SizeX();
        }

        if (y >= SizeY()) {
            new_y = y % SizeY();
        } else if (y < 0) {
            new_y = y + SizeY();
        }

        return IsAlive(new_x, new_y);
    } else {
        return m_board.at(Index(x, y));
    }
}

void ConwayLife::SetAlive(const int x, const int y) {
    m_board.at(Index(x, y)) = ConwayLifeStatus::alive;
}

void ConwayLife::SetDead(const int x, const int y) {
    m_board.at(Index(x, y)) = ConwayLifeStatus::dead;
}

void ConwayLife::CalcNextGeneration() {
    // compute next generation of board
    
    // to do this, we need to evaluate all rules on CURRENT state of board,
    // making any changes on a new copy of the board
    auto newBoard = std::make_unique<ConwayLife>(SizeX(), SizeY());

    for (int y=0; y<SizeY(); y++) {
        for (int x=0; x<SizeX(); x++) {
            ConwayLifeStatus newState = CalcNewCellState(x, y);
            if (newState == ConwayLifeStatus::alive) {
                newBoard->SetAlive(x, y);
            } else {
                // the board is already initialized to dead so we shouldn't
                // need to do this?
                newBoard->SetDead(x, y);
            }
        }
    }

    // once complete, we will then set our current board to point to our new
    // board, discarding the old board

    // TODO right now we're copying the board over through public access.
    // FIX THIS!
    std::copy(newBoard->m_board.begin(), newBoard->m_board.end(), m_board.begin());

    m_generation++;
}

auto ConwayLife::CalcNewCellState(const int x, const int y) const -> ConwayLifeStatus {
    // rules (from Wikipedia):
    // - Any live cell with two or three live neighbours survives.
    // - Any dead cell with three live neighbours becomes a live cell.
    // - All other live cells die in the next generation. Similarly, all other
    //   dead cells stay dead.

    int numLivingNeighbors(CountAliveNeighbors(x, y));
    if (IsAlive(x, y)) {
        if (numLivingNeighbors >= 2 && numLivingNeighbors <= 3) {
            // live cell with 2 or 3 live neighbors, so stays living
            return ConwayLifeStatus::alive;
        } else {
            // live cell with either less than 2 live
            // neighbors (underpopulation) or more than 3 (overpopulation)
            // either way, dies
            return ConwayLifeStatus::dead;
        }
    } else if (numLivingNeighbors == 3) {
        // reproduction
        return ConwayLifeStatus::alive;
    } else {
        // dead cell stays dead
        return ConwayLifeStatus::dead;
    }
}



auto ConwayLife::CountAliveNeighbors(const int x, const int y) const -> int {
    // count how many of the 8 neighbors surrounding this cell are alive
    int count(0);

    int x1(x-1);
    int x2(x+1);
    int y1(y-1);
    int y2(y+1);

    if (IsAlive(x1, y1)) count++;
    if (IsAlive(x1, y)) count++;
    if (IsAlive(x1, y2)) count++;

    if (IsAlive(x, y1)) count++;
    if (IsAlive(x, y2)) count++;

    if (IsAlive(x2, y1)) count++;
    if (IsAlive(x2, y)) count++;
    if (IsAlive(x2, y2)) count++;

    return count;
}