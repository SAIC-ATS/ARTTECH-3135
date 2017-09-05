# Contributing

## Fork and Install Contributing Installation (optional)

1. Fork [the repository](https://github.com/SAIC-ATS/ARTTECH-3135) on github.
2. In the terminal, change your working directory to the openFrameworks root:
  - `cd OF_ROOT/`
3. Clone the repository, filling in `GITHUB_USERNAME` with _your_ Github user name.
  - `git clone https://github.com/GITHUB_USERNAME/ARTTECH-3135.git`
4. Create a remote link to the main repository and call it _upstream_
  - `git remote add https://github.com/SAIC-ATS/ARTTECH-3135.git`
5. To update your copy to the latest upstream ..
  - `git pull upstream master`

  If, when updating your fork, you get a terminal screen that looks like:

  ```
  Merge branch 'master' of https://github.com/SAIC-ATS/ARTTECH-3135

  # Please enter a commit message to explain why this merge is necessary,
  # especially if it merges an updated upstream into a topic branch.
  #
  # Lines starting with '#' will be ignored, and an empty message aborts
  # the commit.
  ~             
  ~
  ~
  ~
  ~
  ```

... it means that your git wants you to issue a commit message and the default terminal text editor is set to `vim`. `vim` is a powerful [text editor](http://www.openvim.com/), but not for the faint of heart. To exit out of that screen, you should use the following key sequence:

`ESCAPE`, `:`, `w`, `q`, `ENTER`

This will simply allow the merge to proceed with the default message.

If you would like to switch your default text editor to something simpler, like `nano`, configure git like this:

```
git config --global core.editor "nano"
```

If you'd like to use a GUI based text editor, you can use something like Atom.io by following [these instructions](https://stackoverflow.com/a/31389989/1518329).

### Submitting Changes

If you find errors or want to make contributions ...

1. Install this repository as a contributor (see above).
2. Create your feature branch (`git checkout -b my-new-feature`).
3. Commit your changes (`git commit -am 'Add some feature'`).
4. Push to the branch (`git push origin my-new-feature`).
5. Create new Pull Request.
