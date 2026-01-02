*This project has been created as part of the 42 curriculum by sgil--de, tmalpert.*

# push_swap

## Description

`push_swap` is a sorting project where you must sort a stack of integers using a very limited set of operations on two stacks (A and B). The program outputs the minimal (or near-minimal) sequence of operations to sort the input numbers in ascending order. Constraints include:
- Only allowed operations: `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`.
- No direct access to arbitrary indices; you manipulate stack tops via pushes, swaps, and rotations.
- Efficiency matters: fewer operations is better, and time/memory complexity must remain reasonable.

This implementation includes multiple strategies selected by input size:
- Tiny inputs: tailored small-sort routines (selection-like behavior).
- Medium inputs: chunk-based sorting.
- Large inputs: LSD radix sort.

## Instructions

### Build
The project uses a `Makefile` and depends on the bundled `libft`.

```bash
make            # builds the push_swap binary
make clean      # removes object files
make fclean     # removes objects + binaries
make re         # rebuild from scratch
```

After building, an executable `push_swap` is generated at the repository root.

### Run
Provide a list of integers via command-line arguments. The program prints the sequence of operations to stdout.

```bash
./push_swap 2 1 3 6 5 8
```

If the input is already sorted, the program prints nothing. Invalid inputs (non-integers, duplicates, overflow) are rejected according to the project rules.

### Checker (Linux)
This repository includes a `checker_linux` tool for local verification. To test the sequence produced by `push_swap`:

```bash
ARG="3 2 5 1 4"
./push_swap $ARG | ./checker_linux $ARG
```

The checker outputs `OK` if the sequence sorts correctly and `KO` otherwise.

### Examples
Generate and test random inputs (Linux):

```bash
ARG=$(seq 1 100 | shuf | xargs)
./push_swap $ARG | ./checker_linux $ARG
```

To inspect the number of operations generated:

```bash
ARG=$(seq 1 100 | shuf | xargs)
OPS=$(./push_swap $ARG | wc -l)
echo "Operations: $OPS"
```

## Algorithms: Explanation and Justification

This codebase implements three complementary strategies, chosen by input size and characteristics. The goal is to balance simplicity, correctness, and operation count.

### Allowed operations (semantic overview)

- `sa` / `sb`: swap the first two elements on stack A/B.
- `ss`: perform `sa` and `sb` simultaneously.
- `pa`: push the top of B onto A.
- `pb`: push the top of A onto B.
- `ra` / `rb`: rotate A/B upwards (top becomes bottom).
- `rr`: perform `ra` and `rb` simultaneously.
- `rra` / `rrb`: reverse rotate A/B (bottom becomes top).
- `rrr`: perform `rra` and `rrb` simultaneously.

You only observe and manipulate the top of each stack; all strategies below are framed in terms of these operations.

### Small inputs: Selection-style small-sort
For tiny sets (e.g., 3–5 elements), specialized routines derived from selection/insertion logic are used. These perform a minimal set of swaps and rotations based on local comparisons, often reaching optimal sequences for `n <= 5`.

Justification:
- Minimal overhead and near-optimal results are achievable with handcrafted cases.
- Avoids the setup cost of chunking or bitwise passes.

Complexity: $O(n^2)$ in the general case, but with tiny $n$ the constant factors dominate and the sequences are short.

Step-by-step (typical patterns):
- For 3 elements in A:
	- If A[0] > A[1], `sa`.
	- If A is not sorted and the max is at top, `ra`; if the min is at bottom, `rra`.
	- Combined cases (examples):
		- `[2,1,3]` → `sa`
		- `[3,2,1]` → `sa` then `rra`
		- `[3,1,2]` → `ra`
		- `[1,3,2]` → `sa` then `ra`
- For 5 elements in A:
	- Push the two smallest to B using selective rotations (`pb` twice), keeping A roughly ordered.
	- Sort the remaining 3 in A using the 3-element routine.
	- Bring the smallest on B to the top if needed (`rb`/`rrb`), then `pa` twice, inserting in order.
	- Occasionally finish with a small rotation if the last insertion altered the head.

### Medium inputs: Chunk-based sorting
The set is divided into value-ordered chunks (e.g., by rank). Elements are pushed from A to B chunk by chunk, favoring rotations that minimize movement. Once a chunk is fully in B, elements are reinserted into A in the correct order.

Justification:
- Reduces search scope via chunk boundaries, leading to fewer rotations.
- Strong practical performance for ~100 elements compared to naive selection.

Complexity: Typically around $O(n \log n)$ rotations/pushes in practice due to locality and guided placement, though worst-case reasoning depends on chunk strategy.

Workflow (high-level algorithm):
1. Rank inputs (0..n-1) so comparisons are consistent and overflow/negatives are handled.
2. Choose a chunk size (e.g., based on n). Compute chunk boundaries on ranks.
3. For each chunk:
	 - Scan A; when the top is in the current chunk, `pb` to move to B.
	 - Use `ra`/`rra` to bring target values near the top before `pb` to reduce moves.
	 - On B, keep elements roughly in descending order (future `pa`s will restore ascending order in A). Use `rb`/`rrb` to place near correct side.
4. After all chunks are moved to B, push back:
	 - While B not empty, rotate B to bring its current maximum to top, then `pa`.
	 - Optionally use `ra` to maintain ordering continuity in A.

Pseudocode (schematic):

```text
rank = compress_to_ranks(A)
chunks = partition(rank, chunk_size)
for each chunk in chunks:
	while exists elements of chunk in A:
		rotate A (ra/rra) toward target; pb
		place in B using rb/rrb to keep B roughly descending
while B not empty:
	rotate B to max; pa
```

### Large inputs: LSD Radix Sort on indices
Map input values to ranks (0..n-1), then perform least-significant-bit (LSD) passes:
- For each bit position $k$, iterate A and push to B those whose bit $k$ is 0; rotate otherwise.
- After a pass, push everything back from B to A.

Justification:
- Stable, simple, and deterministic with excellent scalability.
- Operation count scales roughly with $n \cdot \text{number of bits}$, i.e., $O(n \log n)$.

Trade-offs:
- May not be strictly minimal, but yields consistent low counts for large inputs.

Workflow (detailed):
1. Map values to ranks in [0..n-1]. This removes the need to handle large ranges or negatives.
2. Let `max_bits` be the number of bits of `max(rank)`.
3. For `bit` in `0..max_bits-1`:
	 - For `i` in `0..n-1` (iterate over all items currently in A):
		 - If `((A.top.rank >> bit) & 1) == 0`: `pb` (send to B).
		 - Else: `ra` (keep in A, cycle to bottom).
	 - When the pass ends, `pa` repeatedly to move all from B back to A.

Example (ranks):
- Input values `[40, -2, 7, 1]` → ranks `[3, 0, 2, 1]`.
- `bit=0`: push 0s to B, rotate 1s in A; `pa` all back.
- `bit=1`, `bit=2`: repeat. After last pass, A is sorted by rank (thus by value).

Correctness sketch and invariants:
- Radix passes are stable on ranks; each pass partitions by a bit while preserving prior ordering for elements with the same bit.
- Termination: after `max_bits` passes, all bits have been processed; ranks are in ascending order.
- Safety: using ranks ensures uniform handling of negatives and large numbers.

### Implementation notes (files)
- `srcs/algorithme/selection_sort.c`: small-sort routines.
- `srcs/algorithme/chunk_sort.c` and `chunk_utils.c`: chunk partitioning and guided moves.
- `srcs/algorithme/radix_sort.c`: rank mapping + bitwise passes.
- Core operations: `srcs/list/push.c`, `swap.c`, `rotate.c` implement `pa/pb`, `sa/sb/ss`, `ra/rb/rr` and reverse rotations where applicable.
- Parsing and validation: `srcs/parsing/parsing.c` ensures proper inputs.

## Technical choices

- Language: C.
- Utility library: `libs/libft` provides common functions and `ft_printf`.
- Data structures: linked-list stacks (nodes hold integer value + metadata as needed).
- Error handling: input validation (duplicates, non-numeric, overflow), graceful exits.
- Performance: separate algorithms per size class; optional `bench.c` supports rough comparisons.

## Resources and AI usage

Classic references used during development:
- GeeksforGeeks (concepts and algorithm refreshers):
	- Stacks and basic operations: https://www.geeksforgeeks.org/stack-data-structure/
	- Selection sort: https://www.geeksforgeeks.org/selection-sort/
    - Chunk sort : https://www.cs.upc.edu/~conrado/research/talks/dmd06.pdf
	- Radix sort (LSD): https://www.geeksforgeeks.org/radix-sort/
	- Linked lists: https://www.geeksforgeeks.org/data-structures/linked-list/

AI usage disclosure:
- Chat GPT was used to assist in drafting this README and answer my questions about algorithms.