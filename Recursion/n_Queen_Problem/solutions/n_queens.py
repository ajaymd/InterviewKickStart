def find_all_arrangements(n):
    # fill the board initially
    board = [x for x in range(n)]
    output = []
    _generate_n_queens(board, 0, n, output)
    return generate_output(output)


def generate_output(boards):
    output = []
    for arr in boards:
        o = [['-'] * len(arr) for _ in range(len(arr))]
        for r, c in enumerate(arr):
            o[r][c] = 'q'
        # join rows
        output.append([''.join(row) for row in o])
    return output


def print_board(arr):
    output = [['-'] * len(arr) for _ in range(len(arr))]
    for r, c in enumerate(arr):
        output[r][c] = 'q'
    return output


def _generate_n_queens(board, start, n, output):
    # base condition
    if start == n:
        output.append([x for x in board])
        return

    for i in range(start, n):
        swap(board, start, i)
        if _is_board_valid(board, start):
            # only continue if board is valid
            _generate_n_queens(board, start + 1, n, output)
        swap(board, start, i)


def swap(arr, i, j):
    arr[i], arr[j] = arr[j], arr[i]


def _is_board_valid(board, i):
    # check if board is valid from start to current index
    # we only need to check diagonal conflicts as row and columns won't conflic
    r1 = i
    c1 = board[i]

    for r2, c2 in enumerate(board[:i]):
        if abs(r1-r2) == abs(c1-c2):
            return False
    return True


for i in range(6):
    print find_all_arrangements(i)