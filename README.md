GIT repository for csci375/Team1/Project
For build instructions please see csci375/Project/project/README.md

Git work flow full instructions: https://docs.google.com/document/d/1yDrKHy_FKFAiht0kuio0eLCiNl0PRdey8jiubZBCX9M/edit?usp=sharing


# Important note about Makefiles
This project has two makefiles. One in csci375/Project and one in csci375/Project/project.

- csci375/Project/makefile is for git submission (explained below)
- csci375/Project/project/Makefile is for project compilation (explained in csci375/Project/project/README)



# Git Procedure

## Setup
Create your own branch for development:
`git checkout -b "<yourbranchname>"`

Note: Make your branch name small because you will have to type it in a lot and you can't tab-complete it.

## Pushing to Master
There are 2 steps
### Step 1
Make sure you only have 1 commit to push. Enter this command:
`make push`
If you get merge conflicts, you can do git status to see the conflicting files. Open them and resolve the changes.

Note the below commands should be run from the csci375/Project/project directory
Do `make run` and (when we have it) `make test` to confirm that resolving the conflicts didn't brake anything.
do `git add` for all the files that were conflicting then do `git cherry-pick --continue`

### Step 2
Once your conflicts are resolved, do `make push2 b="<yourbranchname>"`

## Updating Your Branch
to update your branch and the local master branch do `make pull b="<yourbranchname>"`

