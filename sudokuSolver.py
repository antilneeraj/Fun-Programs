class Solution:
    
    def SolveSudoku(self, grid):
        # Find an empty cell
        empty_cell = self.findEmptyCell(grid)
        if not empty_cell:
            return True  # No empty cells left, Sudoku solved
        
        row, col = empty_cell
        
        # Try numbers 1 to 9
        for num in range(1, 10):
            if self.isValidMove(grid, row, col, num):
                grid[row][col] = num
                
                if self.SolveSudoku(grid):
                    return True  # Move successful, continue solving
                
                grid[row][col] = 0  # If no solution found, backtrack
        
        return False  # No valid number found, need to backtrack
    
    def findEmptyCell(self, grid):
        for i in range(9):
            for j in range(9):
                if grid[i][j] == 0:
                    return i, j
        return None
    
    def isValidMove(self, grid, row, col, num):
        # Check if num is in the current row, column, and sub-grid
        return (not self.inRow(grid, row, num) and
                not self.inCol(grid, col, num) and
                not self.inSubGrid(grid, row - row % 3, col - col % 3, num))
    
    def inRow(self, grid, row, num):
        return num in grid[row]
    
    def inCol(self, grid, col, num):
        return any(row[col] == num for row in grid)
    
    def inSubGrid(self, grid, startRow, startCol, num):
        return any(grid[startRow + i][startCol + j] == num
                   for i in range(3) for j in range(3))
    
    def printGrid(self, grid):
        for row in grid:
            print(" ".join(map(str, row)))

# Example usage
input_grid = [
    [3, 0, 6, 5, 0, 8, 4, 0, 0],
    [5, 2, 0, 0, 0, 0, 0, 0, 0],
    [0, 8, 7, 0, 0, 0, 0, 3, 1],
    [0, 0, 3, 0, 1, 0, 0, 8, 0],
    [9, 0, 0, 8, 6, 3, 0, 0, 5],
    [0, 5, 0, 0, 9, 0, 6, 0, 0],
    [1, 3, 0, 0, 0, 0, 2, 5, 0],
    [0, 0, 0, 0, 0, 0, 0, 7, 4],
    [0, 0, 5, 2, 0, 6, 3, 0, 0]
]

solver = Solution()
if solver.solveSudoku(input_grid):
    solver.printGrid(input_grid)
else:
    print("No solution exists.")
