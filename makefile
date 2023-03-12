 MY_VAR := $(shell git log --oneline -1)
ID = $(shell echo ${MY_VAR} | head -c 7)

# Do a git commit with a descriptive commit message
# squash all your new commits into 1

# when you're ready, run `make push`, fix any merges, and then run `make push2 b=<yourbranch>`
push:
	git stash
	git checkout master
	git fetch
	git reset --hard origin/master
	git cherry-pick ${ID}
# Resolve any merge conflicts
push2: # run `make push2 b=<yourbranch>`
	git push
	git checkout ${b}
	git stash pop

# the below command will update your branch with the lastest changes on master/main
# commit and push (on your own branch) any changes you care about first! Or add them
# This will not delete any of your work
# you will likely have merge issues
# Note: makefile will say there was an error if you didn't have any changes to stash, you can ignore that
pull:
	git stash
	git fetch
	git rebase master
	git stash pop

# Note2: if you get this error: "error: The following untracked working tree files would be overwritten by merge:" it is
# because you have untracked files, so add them, commit them, delete them, or save them somewhere else
# if it's just your build/* and bin/* folders then do `make clean`