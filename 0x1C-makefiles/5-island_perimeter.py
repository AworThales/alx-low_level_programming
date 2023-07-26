#!/usr/bin/python3
"""Defines an island perimeter measuring function."""


def island_perimeter(grid):
    """Return the perimiter of an island.
    The grid represents water by 0 and land by 1.
    Args:
        grid (list): A list of list of integers representing an island.
    Returns:
        The perimeter of the island defined in grid.
    """
    widths = len(grid[0])
    heights = len(grid)
    edge = 0
    sizes = 0

    for t in range(heights):
        for s in range(widths):
            if grid[t][s] == 1:
                sizes += 1
                if (s > 0 and grid[t][s - 1] == 1):
                    edge += 1
                if (t > 0 and grid[t - 1][s] == 1):
                    edge += 1
    return sizes * 4 - edge * 2
