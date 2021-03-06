#pragma once

#include "armaheader.h"
const std::vector< std::vector<int> > gencodes {
    std::vector<int> {2, 2, 2, 2},
    std::vector<int> {-9, 2, 2, 2},
    std::vector<int> {1, 2, 2, 2},
    std::vector<int> {0, 2, 2, 2},
    std::vector<int> {2, -9, 2, 2},
    std::vector<int> {-9, -9, 2, 2},
    std::vector<int> {1, -9, 2, 2},
    std::vector<int> {0, -9, 2, 2},
    std::vector<int> {2, 1, 2, 2},
    std::vector<int> {-9, 1, 2, 2},
    std::vector<int> {1, 1, 2, 2},
    std::vector<int> {0, 1, 2, 2},
    std::vector<int> {2, 0, 2, 2},
    std::vector<int> {-9, 0, 2, 2},
    std::vector<int> {1, 0, 2, 2},
    std::vector<int> {0, 0, 2, 2},
    std::vector<int> {2, 2, -9, 2},
    std::vector<int> {-9, 2, -9, 2},
    std::vector<int> {1, 2, -9, 2},
    std::vector<int> {0, 2, -9, 2},
    std::vector<int> {2, -9, -9, 2},
    std::vector<int> {-9, -9, -9, 2},
    std::vector<int> {1, -9, -9, 2},
    std::vector<int> {0, -9, -9, 2},
    std::vector<int> {2, 1, -9, 2},
    std::vector<int> {-9, 1, -9, 2},
    std::vector<int> {1, 1, -9, 2},
    std::vector<int> {0, 1, -9, 2},
    std::vector<int> {2, 0, -9, 2},
    std::vector<int> {-9, 0, -9, 2},
    std::vector<int> {1, 0, -9, 2},
    std::vector<int> {0, 0, -9, 2},
    std::vector<int> {2, 2, 1, 2},
    std::vector<int> {-9, 2, 1, 2},
    std::vector<int> {1, 2, 1, 2},
    std::vector<int> {0, 2, 1, 2},
    std::vector<int> {2, -9, 1, 2},
    std::vector<int> {-9, -9, 1, 2},
    std::vector<int> {1, -9, 1, 2},
    std::vector<int> {0, -9, 1, 2},
    std::vector<int> {2, 1, 1, 2},
    std::vector<int> {-9, 1, 1, 2},
    std::vector<int> {1, 1, 1, 2},
    std::vector<int> {0, 1, 1, 2},
    std::vector<int> {2, 0, 1, 2},
    std::vector<int> {-9, 0, 1, 2},
    std::vector<int> {1, 0, 1, 2},
    std::vector<int> {0, 0, 1, 2},
    std::vector<int> {2, 2, 0, 2},
    std::vector<int> {-9, 2, 0, 2},
    std::vector<int> {1, 2, 0, 2},
    std::vector<int> {0, 2, 0, 2},
    std::vector<int> {2, -9, 0, 2},
    std::vector<int> {-9, -9, 0, 2},
    std::vector<int> {1, -9, 0, 2},
    std::vector<int> {0, -9, 0, 2},
    std::vector<int> {2, 1, 0, 2},
    std::vector<int> {-9, 1, 0, 2},
    std::vector<int> {1, 1, 0, 2},
    std::vector<int> {0, 1, 0, 2},
    std::vector<int> {2, 0, 0, 2},
    std::vector<int> {-9, 0, 0, 2},
    std::vector<int> {1, 0, 0, 2},
    std::vector<int> {0, 0, 0, 2},
    std::vector<int> {2, 2, 2, -9},
    std::vector<int> {-9, 2, 2, -9},
    std::vector<int> {1, 2, 2, -9},
    std::vector<int> {0, 2, 2, -9},
    std::vector<int> {2, -9, 2, -9},
    std::vector<int> {-9, -9, 2, -9},
    std::vector<int> {1, -9, 2, -9},
    std::vector<int> {0, -9, 2, -9},
    std::vector<int> {2, 1, 2, -9},
    std::vector<int> {-9, 1, 2, -9},
    std::vector<int> {1, 1, 2, -9},
    std::vector<int> {0, 1, 2, -9},
    std::vector<int> {2, 0, 2, -9},
    std::vector<int> {-9, 0, 2, -9},
    std::vector<int> {1, 0, 2, -9},
    std::vector<int> {0, 0, 2, -9},
    std::vector<int> {2, 2, -9, -9},
    std::vector<int> {-9, 2, -9, -9},
    std::vector<int> {1, 2, -9, -9},
    std::vector<int> {0, 2, -9, -9},
    std::vector<int> {2, -9, -9, -9},
    std::vector<int> {-9, -9, -9, -9},
    std::vector<int> {1, -9, -9, -9},
    std::vector<int> {0, -9, -9, -9},
    std::vector<int> {2, 1, -9, -9},
    std::vector<int> {-9, 1, -9, -9},
    std::vector<int> {1, 1, -9, -9},
    std::vector<int> {0, 1, -9, -9},
    std::vector<int> {2, 0, -9, -9},
    std::vector<int> {-9, 0, -9, -9},
    std::vector<int> {1, 0, -9, -9},
    std::vector<int> {0, 0, -9, -9},
    std::vector<int> {2, 2, 1, -9},
    std::vector<int> {-9, 2, 1, -9},
    std::vector<int> {1, 2, 1, -9},
    std::vector<int> {0, 2, 1, -9},
    std::vector<int> {2, -9, 1, -9},
    std::vector<int> {-9, -9, 1, -9},
    std::vector<int> {1, -9, 1, -9},
    std::vector<int> {0, -9, 1, -9},
    std::vector<int> {2, 1, 1, -9},
    std::vector<int> {-9, 1, 1, -9},
    std::vector<int> {1, 1, 1, -9},
    std::vector<int> {0, 1, 1, -9},
    std::vector<int> {2, 0, 1, -9},
    std::vector<int> {-9, 0, 1, -9},
    std::vector<int> {1, 0, 1, -9},
    std::vector<int> {0, 0, 1, -9},
    std::vector<int> {2, 2, 0, -9},
    std::vector<int> {-9, 2, 0, -9},
    std::vector<int> {1, 2, 0, -9},
    std::vector<int> {0, 2, 0, -9},
    std::vector<int> {2, -9, 0, -9},
    std::vector<int> {-9, -9, 0, -9},
    std::vector<int> {1, -9, 0, -9},
    std::vector<int> {0, -9, 0, -9},
    std::vector<int> {2, 1, 0, -9},
    std::vector<int> {-9, 1, 0, -9},
    std::vector<int> {1, 1, 0, -9},
    std::vector<int> {0, 1, 0, -9},
    std::vector<int> {2, 0, 0, -9},
    std::vector<int> {-9, 0, 0, -9},
    std::vector<int> {1, 0, 0, -9},
    std::vector<int> {0, 0, 0, -9},
    std::vector<int> {2, 2, 2, 1},
    std::vector<int> {-9, 2, 2, 1},
    std::vector<int> {1, 2, 2, 1},
    std::vector<int> {0, 2, 2, 1},
    std::vector<int> {2, -9, 2, 1},
    std::vector<int> {-9, -9, 2, 1},
    std::vector<int> {1, -9, 2, 1},
    std::vector<int> {0, -9, 2, 1},
    std::vector<int> {2, 1, 2, 1},
    std::vector<int> {-9, 1, 2, 1},
    std::vector<int> {1, 1, 2, 1},
    std::vector<int> {0, 1, 2, 1},
    std::vector<int> {2, 0, 2, 1},
    std::vector<int> {-9, 0, 2, 1},
    std::vector<int> {1, 0, 2, 1},
    std::vector<int> {0, 0, 2, 1},
    std::vector<int> {2, 2, -9, 1},
    std::vector<int> {-9, 2, -9, 1},
    std::vector<int> {1, 2, -9, 1},
    std::vector<int> {0, 2, -9, 1},
    std::vector<int> {2, -9, -9, 1},
    std::vector<int> {-9, -9, -9, 1},
    std::vector<int> {1, -9, -9, 1},
    std::vector<int> {0, -9, -9, 1},
    std::vector<int> {2, 1, -9, 1},
    std::vector<int> {-9, 1, -9, 1},
    std::vector<int> {1, 1, -9, 1},
    std::vector<int> {0, 1, -9, 1},
    std::vector<int> {2, 0, -9, 1},
    std::vector<int> {-9, 0, -9, 1},
    std::vector<int> {1, 0, -9, 1},
    std::vector<int> {0, 0, -9, 1},
    std::vector<int> {2, 2, 1, 1},
    std::vector<int> {-9, 2, 1, 1},
    std::vector<int> {1, 2, 1, 1},
    std::vector<int> {0, 2, 1, 1},
    std::vector<int> {2, -9, 1, 1},
    std::vector<int> {-9, -9, 1, 1},
    std::vector<int> {1, -9, 1, 1},
    std::vector<int> {0, -9, 1, 1},
    std::vector<int> {2, 1, 1, 1},
    std::vector<int> {-9, 1, 1, 1},
    std::vector<int> {1, 1, 1, 1},
    std::vector<int> {0, 1, 1, 1},
    std::vector<int> {2, 0, 1, 1},
    std::vector<int> {-9, 0, 1, 1},
    std::vector<int> {1, 0, 1, 1},
    std::vector<int> {0, 0, 1, 1},
    std::vector<int> {2, 2, 0, 1},
    std::vector<int> {-9, 2, 0, 1},
    std::vector<int> {1, 2, 0, 1},
    std::vector<int> {0, 2, 0, 1},
    std::vector<int> {2, -9, 0, 1},
    std::vector<int> {-9, -9, 0, 1},
    std::vector<int> {1, -9, 0, 1},
    std::vector<int> {0, -9, 0, 1},
    std::vector<int> {2, 1, 0, 1},
    std::vector<int> {-9, 1, 0, 1},
    std::vector<int> {1, 1, 0, 1},
    std::vector<int> {0, 1, 0, 1},
    std::vector<int> {2, 0, 0, 1},
    std::vector<int> {-9, 0, 0, 1},
    std::vector<int> {1, 0, 0, 1},
    std::vector<int> {0, 0, 0, 1},
    std::vector<int> {2, 2, 2, 0},
    std::vector<int> {-9, 2, 2, 0},
    std::vector<int> {1, 2, 2, 0},
    std::vector<int> {0, 2, 2, 0},
    std::vector<int> {2, -9, 2, 0},
    std::vector<int> {-9, -9, 2, 0},
    std::vector<int> {1, -9, 2, 0},
    std::vector<int> {0, -9, 2, 0},
    std::vector<int> {2, 1, 2, 0},
    std::vector<int> {-9, 1, 2, 0},
    std::vector<int> {1, 1, 2, 0},
    std::vector<int> {0, 1, 2, 0},
    std::vector<int> {2, 0, 2, 0},
    std::vector<int> {-9, 0, 2, 0},
    std::vector<int> {1, 0, 2, 0},
    std::vector<int> {0, 0, 2, 0},
    std::vector<int> {2, 2, -9, 0},
    std::vector<int> {-9, 2, -9, 0},
    std::vector<int> {1, 2, -9, 0},
    std::vector<int> {0, 2, -9, 0},
    std::vector<int> {2, -9, -9, 0},
    std::vector<int> {-9, -9, -9, 0},
    std::vector<int> {1, -9, -9, 0},
    std::vector<int> {0, -9, -9, 0},
    std::vector<int> {2, 1, -9, 0},
    std::vector<int> {-9, 1, -9, 0},
    std::vector<int> {1, 1, -9, 0},
    std::vector<int> {0, 1, -9, 0},
    std::vector<int> {2, 0, -9, 0},
    std::vector<int> {-9, 0, -9, 0},
    std::vector<int> {1, 0, -9, 0},
    std::vector<int> {0, 0, -9, 0},
    std::vector<int> {2, 2, 1, 0},
    std::vector<int> {-9, 2, 1, 0},
    std::vector<int> {1, 2, 1, 0},
    std::vector<int> {0, 2, 1, 0},
    std::vector<int> {2, -9, 1, 0},
    std::vector<int> {-9, -9, 1, 0},
    std::vector<int> {1, -9, 1, 0},
    std::vector<int> {0, -9, 1, 0},
    std::vector<int> {2, 1, 1, 0},
    std::vector<int> {-9, 1, 1, 0},
    std::vector<int> {1, 1, 1, 0},
    std::vector<int> {0, 1, 1, 0},
    std::vector<int> {2, 0, 1, 0},
    std::vector<int> {-9, 0, 1, 0},
    std::vector<int> {1, 0, 1, 0},
    std::vector<int> {0, 0, 1, 0},
    std::vector<int> {2, 2, 0, 0},
    std::vector<int> {-9, 2, 0, 0},
    std::vector<int> {1, 2, 0, 0},
    std::vector<int> {0, 2, 0, 0},
    std::vector<int> {2, -9, 0, 0},
    std::vector<int> {-9, -9, 0, 0},
    std::vector<int> {1, -9, 0, 0},
    std::vector<int> {0, -9, 0, 0},
    std::vector<int> {2, 1, 0, 0},
    std::vector<int> {-9, 1, 0, 0},
    std::vector<int> {1, 1, 0, 0},
    std::vector<int> {0, 1, 0, 0},
    std::vector<int> {2, 0, 0, 0},
    std::vector<int> {-9, 0, 0, 0},
    std::vector<int> {1, 0, 0, 0},
    std::vector<int> {0, 0, 0, 0}
};
