#### **What is Version Control ?**
- Version control is a system that records changes to files over time, allowing you to track revisions, revert to previous versions, and collaborate on projects.
- Make save points that saves your project.
- provide total development freedom.
- git is a version control tool.
- GitHub is a service that hosts git repositories on a remote server.![[versionControl1.png]]
  ![[versionControl2.png]]
 
  ![[versionControl3.png]]
#### **What is a Repository ?**
- A repository is essentially a folder or directory that is managed by a version control system.
 ![[versionControl4.png]]

#### **What is GitHub ?**
- GitHub provides a remote server that is used for hosting repositories. This service allows developers to store their code online, collaborate with others, and manage projects efficiently.

**Git installation Arch Linux:**
   ```
   sudo pacman -S git // command of installation of git on arch system.
   ```
   
```
git --version // shows version of installed git.
```
**Login :**
```
git config --global user.name "username"
git config --global user.email "email"
git config --list // show the content of config file.
``` 

**How to create git repository :**
- Make a folder for which you want git tool to watch. eg: mkdir dotbatch.
- Open the folder 
```
git init // command to turn the current folder into a git repository.
```

```
git status // command is used to check the status of git repository.
``` 

**To clone git repository from a remoter server : **
```
git clone URL <folder_name> //this command is used for cloning of the repository form a remote server.
```
- Here **folder_name** is not necessary.

#### **Life Cycle of Change :-**
![[lifeCycleofChange.png]]
- Commit is permanent change , save point.
### **Git Staging Phases:**

1. **Working Directory:**
    
    - This is where you make changes to your files. These changes are not yet tracked by Git.
2. **Staging Area (Index):**
    
    - After you use `git add <file>`, the changes are moved from the working directory to the staging area (also called the index). This means the changes are prepared and staged for the next commit.
3. **Repository (Committed State):**
    
    - Once you commit the changes using `git commit`, the changes from the staging area are saved into the repository as a new commit.

**Commands related to git commit :**
```
git log //shows all commits history.
git log -3 // will show latest 3 commits.
git log -p // will show commit and changes done.
git log --oneline // use to list in one line SHA id and message.
git log --stat // tells which file were modified, but doesn't where the change is happened.
git show SHA_id // will show what changes were done in a particular commit.
```
**Lets make a Commit :**
```
git add <file_name> // add file to track.
```
- new_files are added to track.
- old_files are put into staging index.
```
git commit -m "some_message" // will be used to commit file to repository. 
```
- -m for message for commit.
- **git add .** is not recommended because it will put all file on staging index stage.
 ![[headOfCommit.png]]
```
git restore <file_name> // will discard any change and we will go to the latest commit(Head).
```
 - **.gitignore** file is used to ignore the file that we don't want to be watched by git .
 - ![[ignoreFile.png]]we can add file_names, path to file_name etc.
 
#### **Branching, Tagging & Merging:-**
![[branching.png]]
- Initially one branch. ( with two files file1 and file2).
- Main branch is super maintained / working, other branches are experimental branch / feature branches.
- We can make custom branches.
- Branch B and C , both B and C will have the copy of A3 commit code.
- Now C1 and B1 are new commits and both of them have changed content of different files (file1,file2) 
- When are on branch B we edit file1 this edit will only happen in Branch B because we have copied the content of A3 commit,both Branch B and C will have different copies.
- Both branches are independent of one another.
- Let say B2 is the final commit of branch B, then A3 and B2 will get merged and form a new commit.
- 
- * shows in which branch we are currently in. 

**Branching related commands:-**
```
git branch <branchName> // for creating a new branch.
```

```
git checkout <branckName> // for switching to particular branch.
```

```
git branch // will output in which brach you are in.
```
- * show on which branch you are currently on.
```
git checkout -b <brancName> // to create brach and move to brach.
```

```
git -am "message" // to add + commit + message.
```

**Lets say we are done with some branch,follow these steps to merge to main branch:-**
- First checkout to master branch and then do.
```
git merge <mergingBranchName> // mergingBranchName= name of branch you want to merge.
```

**Lets say we are done with merging and don't want the branch,we can delete the branch:-**

```
git branch -d <branchName> // -d for deleting branch.
```

#### **Why branch ?**
- We want to develop independent feature, or to collaborate with other peoples,and at the end i want to merge / integrate the feature to main / master branch /main project.

#### **What is merge conflict ?**
- A merge conflict in Git happens when Git can't automatically reconcile differences between two branches that you're trying to merge. This typically occurs when changes have been made to the same lines of code or when changes in one branch conflict with changes in another branch.
- high chances it happens with branch but some conflicts and happen even if we don't have branch.

#### **What is Tagging ?**
- Tagging in Git is essentially a way of giving a specific commit a human-readable name. Tags are often used to mark important points in the repository's history, such as releases or milestones.
- **Tag a specific commit (or SHA_id):-**
```
git tag -a <nameOfTag> <commit_id> -m "message"
```
- **Remove Tag:-**

```
git tag -d <tagName>
```

#### **What is a Stash ?** ![[gitStash.png]]
 - To prevent this use we use a command.
```
git stash 
```
- your file will get moved to a stashed area in local machine but file are kind of not present on local repository.
- if we do **git pull** we can get latest remote server files.
```
git stash list // to view stash area.
```

- To un-stash we use .
```
git stash apply
```


#### **Undo commits:-**
```
git commit --amend
```
- This is useful if you forgot to include some files or need to correct the commit message.

```
git revert <SHA_id>
```
- Safely reverses the effects of a commit by applying a new commit that negates the changes of the specified commit.
- This does not alter the commit history.
```
git reset --soft <SHA_id>
```
- Move the HEAD pointer to a specified commit but keep changes in the working directory and index.
- Modification will show as staged, it will be showed in staging index rather than in working directory.
```
git reset --mixed <SHA_id>
```
- Moves the HEAD pointer to a specified commit and keeps changes in the working directory,but not in the indexed.
- The changes will remain intact and they will be showed as modifications.
```
git reset --hard <SHA_id>
```
- Moves the HEAD pointer to a specified commit and discards all changes in the working directory and index.
- All changes will be discarded .

**Push to remote:-**
```
git push -u origin <branchName> // to master branch
```
