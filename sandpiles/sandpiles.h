#ifndef _SANDPILES_H_
#define _SANDPILES_H_

/**
 * struct sandpile_s - Sandpile struct
 * @grid: 3x3 grid
 * Description: Represents a sandpile
 */
typedef struct sandpile_s
{
    int grid[3][3];
} sandpile_t;

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

#endif /* _SANDPILES_H_ */