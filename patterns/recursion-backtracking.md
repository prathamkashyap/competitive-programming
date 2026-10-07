# Recursion and Backtracking Pattern

## When to Recognize

Problems involving:
- Enumerating all possibilities (permutations, combinations, subsets)
- Exploring state spaces with choices
- Constraint satisfaction
- Path finding in graphs/trees
- Combinatorial generation

## Core Idea

Recursively explore all possible choices, applying constraints to prune invalid paths. Backtracking undoes choices when exploring alternatives.

## Common Complexity

- **Brute force**: Exponential
- **Backtracking with pruning**: Still exponential worst-case, but often much faster

## Common Variations

### Subset Generation
Generate all subsets of a set.

**Pattern:**
```cpp
void generate(int index, vector<int>& current) {
    if (index == n) {
        // process current subset
        return;
    }
    // exclude element
    generate(index + 1, current);
    // include element
    current.push_back(a[index]);
    generate(index + 1, current);
    current.pop_back();
}
```

### Permutation Generation
Generate all permutations.

**Pattern:**
```cpp
void generate(vector<int>& a, int index) {
    if (index == n) {
        // process permutation
        return;
    }
    for (int i = index; i < n; i++) {
        swap(a[index], a[i]);
        generate(a, index + 1);
        swap(a[index], a[i]);
    }
}
```

### Constraint Satisfaction
Apply constraints during generation to prune.

**Pattern:**
```cpp
void solve(int pos) {
    if (pos == n) {
        // found valid solution
        return;
    }
    for (int choice : choices[pos]) {
        if (valid(choice, pos)) {
            apply(choice, pos);
            solve(pos + 1);
            undo(choice, pos);
        }
    }
}
```

## Common Pitfalls

- **Stack overflow**: Deep recursion on large inputs
- **Missing backtracking**: Forgetting to undo choices
- **Inefficient pruning**: Weak constraints lead to exponential blowup
- **Duplicate states**: Visiting same state multiple times

**See:** [notes/pitfalls/recursion-and-stack-depth.md](../notes/pitfalls/recursion-and-stack-depth.md)

## Optimization Techniques

- **Memoization**: Cache results of subproblems
- **Pruning**: Cut off branches early based on constraints
- **Iterative deepening**: Limit recursion depth, increase gradually
- **Bitmask representation**: Represent state compactly for small N

## Representative Problems

- N-Queens
- Sudoku
- Hamiltonian path
- Subset sum (small N)
- Graph coloring

## Related Patterns

- [Dynamic Programming](dynamic-programming.md) - Memoization turns recursion into DP
- [Graphs](graphs.md) - DFS is recursive exploration
