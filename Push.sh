#!/bin/sh

./pull.sh
git add --all
git commit -am "Commit $COMMIT_MESSAGE"
git push