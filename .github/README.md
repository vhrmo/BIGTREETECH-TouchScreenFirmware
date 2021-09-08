This is a for of the https://github.com/bigtreetech/BIGTREETECH-TouchScreenFirmware.git

## Cloning

After cloning this fork, set upstream repo:

```
git remote add upstream https://github.com/bigtreetech/BIGTREETECH-TouchScreenFirmware.git
```

and validate it by 

```
git remote -v
```

Github docs: https://docs.github.com/en/get-started/quickstart/fork-a-repo

## Syncing with upstream repo

* Syncing a fork from the command line. 
* For syncing through UI - see https://docs.github.com/en/github/collaborating-with-pull-requests/working-with-forks/syncing-a-fork 

Fetch the branches and their respective commits from the upstream repository. Commits to BRANCHNAME will be stored in the local branch upstream/BRANCHNAME.

    $ git fetch upstream
    > remote: Counting objects: 75, done.
    > remote: Compressing objects: 100% (53/53), done.
    > remote: Total 62 (delta 27), reused 44 (delta 9)
    > Unpacking objects: 100% (62/62), done.
    > From https://github.com/ORIGINAL_OWNER/ORIGINAL_REPOSITORY
    >  * [new branch]      main     -> upstream/main

 Check out your fork's local default branch - in this case, we use main.

     $ git checkout main
     > Switched to branch 'main'

 Merge the changes from the upstream default branch - in this case, upstream/main - into your local default branch. This brings your fork's default branch into sync with the upstream repository, without losing your local changes.

     $ git merge upstream/main
     > Updating a422352..5fdff0f
     > Fast-forward
     >  README                    |    9 -------
     >  README.md                 |    7 ++++++
     >  2 files changed, 7 insertions(+), 9 deletions(-)
     >  delete mode 100644 README
     >  create mode 100644 README.md
     
If your local branch didn't have any unique commits, Git will instead perform a "fast-forward":

     $ git merge upstream/main
     > Updating 34e91da..16c56ad
     > Fast-forward
     >  README.md                 |    5 +++--
     >  1 file changed, 3 insertions(+), 2 deletions(-)

_Tip: Syncing your fork only updates your local copy of the repository. To update your fork on GitHub, you must push your changes._