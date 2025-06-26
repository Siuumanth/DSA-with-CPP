import tkinter as tk
import random
import copy
import time

# ---------- Backtracking with Visualization ----------
def is_valid(board, row, col, num):
    for i in range(9):
        if board[row][i] == num or board[i][col] == num:
            return False
    box_row, box_col = 3 * (row // 3), 3 * (col // 3)
    for i in range(3):
        for j in range(3):
            if board[box_row + i][box_col + j] == num:
                return False
    return True

# GUI Sudoku with step-by-step backtracking
class SudokuGUI:
    def __init__(self, root):
        self.root = root
        self.root.title("Sudoku Solver - Backtracking Visualization")
        self.board, _ = self.generate_puzzle()

        self.entries = [[tk.Entry(root, width=2, font=("Arial", 18), justify="center") for _ in range(9)] for _ in range(9)]
        for i in range(9):
            for j in range(9):
                e = self.entries[i][j]
                e.grid(row=i, column=j, padx=1, pady=1)
                if self.board[i][j] != 0:
                    e.insert(0, str(self.board[i][j]))
                    e.config(state='disabled', disabledforeground='black')

        self.solve_button = tk.Button(root, text="Solve", command=self.start_solving)
        self.solve_button.grid(row=9, column=0, columnspan=9, pady=10)

    def update_gui(self, row, col, value, color):
        e = self.entries[row][col]
        e.config(state='normal')
        e.delete(0, tk.END)
        if value != 0:
            e.insert(0, str(value))
            e.config(disabledforeground=color)
        e.update()
        time.sleep(0.05)
        if value != 0:
            e.config(state='disabled')
        else:
            e.delete(0, tk.END)
        self.root.update()

    def start_solving(self):
        self.solve_with_visual(self.board)

    def solve_with_visual(self, board):
        for row in range(9):
            for col in range(9):
                if board[row][col] == 0:
                    for num in range(1, 10):
                        if is_valid(board, row, col, num):
                            board[row][col] = num
                            self.update_gui(row, col, num, 'green')
                            if self.solve_with_visual(board):
                                return True
                            board[row][col] = 0
                            self.update_gui(row, col, 0, 'red')  # Backtrack
                    return False
        return True

    def generate_puzzle(self):
        board = [[0 for _ in range(9)] for _ in range(9)]
        def fill_diagonal():
            for k in range(0, 9, 3):
                nums = list(range(1, 10))
                random.shuffle(nums)
                for i in range(3):
                    for j in range(3):
                        board[k+i][k+j] = nums.pop()
        fill_diagonal()

        # Ensure it's fully solvable
        solve_sudoku(board)
        full_solution = copy.deepcopy(board)

        # Remove cells to make a puzzle
        cells_to_remove = 40
        while cells_to_remove > 0:
            r, c = random.randint(0, 8), random.randint(0, 8)
            if board[r][c] != 0:
                board[r][c] = 0
                cells_to_remove -= 1

        return board, full_solution


# Helper to fully solve board for puzzle generation
def solve_sudoku(board):
    for row in range(9):
        for col in range(9):
            if board[row][col] == 0:
                for num in range(1, 10):
                    if is_valid(board, row, col, num):
                        board[row][col] = num
                        if solve_sudoku(board):
                            return True
                        board[row][col] = 0
                return False
    return True

# ---------- Run the App ----------
if __name__ == "__main__":
    root = tk.Tk()
    gui = SudokuGUI(root)
    root.mainloop()
