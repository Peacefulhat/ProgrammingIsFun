


## Opening Magit
To open Magit’s **status buffer** for a Git repository:
```elisp
M-x magit-status
```
Or use the shortcut:
```elisp
C-x g
```

## Basic Commands
### Staging Changes
- `s` → Stage a file (like `git add`).
- `S` → Stage all changes.
- `u` → Unstage a file.
- `U` → Unstage all changes.

### Committing Changes
- `c` → Start a commit.
- Write a commit message.
- `C-c C-c` → Confirm commit.

### Pushing and Pulling
- `P p` → Push commits.
- `F p` → Pull changes.

### Checking Logs
- `l l` → View commit history.
- `l g` → View graphical log.

### Branching
- `b c` → Create a new branch.
- `b s` → Switch branches.

### Merging
- `m m` → Merge a branch into the current branch.

### Rebasing
- `r r` → Start an interactive rebase.

## Undoing Changes
- `k` → Discard changes in a file (like `git checkout -- file`).
- `x` → Reset all unstaged changes.

## Advanced Features
### Resolving Merge Conflicts
1. Open Magit with `M-x magit-status`.
2. Navigate to the conflicted file.
3. Use `e` to manually resolve conflicts.
4. Stage (`s`) and commit (`c`).

### Cherry-Picking
- `C` → Cherry-pick a commit from another branch.

### Stashing Changes
- `z z` → Stash changes.
- `z a` → Apply stash.


